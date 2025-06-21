#include <lw/USB/HID_KEY_CODES.h>
#include "MainApp.h"
#include "lw/Pin/PinSTM32F1.h"
#include "lw/Button/SimpleButton.h"
#include "lw/USB/USB_HID_Stm32Helper.h"
#include "lw/USB/HID_Message.h"
#include "PduProcessor.h"

extern USBD_HandleTypeDef hUsbDeviceFS;
static lw::SimpleButton buttonStart({GPIOB, GPIO_PIN_10}, 10);
static lw::SimpleButton buttonKey({GPIOB, GPIO_PIN_11}, 10);
static lw::Pin ledGreen{GPIOB, GPIO_PIN_0, true};
static lw::Pin ledRed{GPIOB, GPIO_PIN_1, true};
static lw::Pin ledNucleo{GPIOC, GPIO_PIN_13};
static PduProcessor pduProcessor(ledGreen, ledRed);

static constexpr uint8_t KEY_MODIFIER_KEY_TURNED = lw::HID::KEY_MOD_LCTRL;
static constexpr uint8_t KEY_MODIFIER_BUTTON_PRESSED = lw::HID::KEY_MOD_LCTRL;
static constexpr uint8_t KEY_CODE_KEY_TURNED = lw::HID::KEY_1;
static constexpr uint8_t KEY_CODE_BUTTON_PRESSED = lw::HID::KEY_2;

static void processNucleoLedToogle(const uint32_t frameTime_ms)
{
	static const uint32_t BLINK_TIME_MS = 300;
	static uint32_t blinkTimer_ms = 0;
	blinkTimer_ms += frameTime_ms;
	if (blinkTimer_ms >= BLINK_TIME_MS)
	{
		blinkTimer_ms -= BLINK_TIME_MS;
		ledNucleo.toogle();
	}
}

void MainApp()
{
	lw::USB_HID::KeyboardMessage keyboardHID;
	keyboardHID.id = 1;
	keyboardHID.modifiers = 0;
	keyboardHID.key1 = 0;
	keyboardHID.key2 = 0;
	keyboardHID.key3 = 0;

	const uint32_t FRAME_TIME_MS = 5;
	const uint32_t USB_HID_WAIT_TIMEOUT_MS = 5;
	auto buttonKeyState = buttonKey.procesTimeout();

	for(int i = 0; i < 20; i++) //check if key turned on on startup
	{
		buttonKeyState = buttonKey.procesTimeout();
		HAL_Delay(FRAME_TIME_MS);
	}

	pduProcessor.init(buttonKeyState == lw::SimpleButtonState::PRESSED);
	while (1)
	{
		HAL_Delay(FRAME_TIME_MS);
		processNucleoLedToogle(FRAME_TIME_MS);
		auto buttonStartState = buttonStart.procesTimeout();
		buttonKeyState = buttonKey.procesTimeout();

		auto pduEvent = pduProcessor.processTimeOut(buttonKeyState == lw::SimpleButtonState::PRESSED, buttonStartState == lw::SimpleButtonState::PRESSED);

		uint8_t key = 0;
		uint8_t keyModifier = 0;
		if(pduEvent == PDU_EVENT::KEY_ON_EVENT)
		{
			key = KEY_CODE_KEY_TURNED;
			keyModifier = KEY_MODIFIER_KEY_TURNED;
		}
		else if(pduEvent == PDU_EVENT::BUTTON_EVENT)
		{
			key = KEY_CODE_BUTTON_PRESSED;
			keyModifier = KEY_MODIFIER_BUTTON_PRESSED;
		}

		if(pduEvent != PDU_EVENT::IDLE)
		{
			keyboardHID.modifiers  = keyModifier;
			keyboardHID.key1 = key;

			if(! lw::USB_HID_Stm32Helper::isReadyBeforeTimeout(&hUsbDeviceFS, USB_HID_WAIT_TIMEOUT_MS))
				continue;
			USBD_HID_SendReport(&hUsbDeviceFS, reinterpret_cast<uint8_t*>(&keyboardHID), sizeof(lw::USB_HID::KeyboardMessage));

			keyboardHID.modifiers  = 0x00;
			keyboardHID.key1 = 0;

			if(! lw::USB_HID_Stm32Helper::isReadyBeforeTimeout(&hUsbDeviceFS, USB_HID_WAIT_TIMEOUT_MS))
				continue;
			USBD_HID_SendReport(&hUsbDeviceFS, reinterpret_cast<uint8_t*>(&keyboardHID), sizeof(lw::USB_HID::KeyboardMessage));
		}
	}
}
