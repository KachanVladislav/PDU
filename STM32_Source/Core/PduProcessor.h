#pragma once
#include "lw/Pin/Pin.h"

enum class PDU_EVENT
{
	IDLE,
	KEY_ON_EVENT,
	BUTTON_EVENT
};

class PduProcessor
{
	enum class PDU_STATE
	{
		KEY_OFF,
		KEY_ON_EVENT,
		KEY_ON,
		KEY_ON_BUTTON_PRESSED_EVENT,
		KEY_ON_BUTTON_ALREADY_PRESSED
	};
	PDU_STATE state = PDU_STATE::KEY_OFF;
	const uint32_t timeout_ms = 5;
	lw::Pin ledGreen;
	lw::Pin ledRed;
	static const uint32_t BLINK_PERIOD_MS = 70;
	static const uint32_t BLINK_QTTY = 2;
	uint32_t blinkTimer_ms = 0;
public:
	PduProcessor(lw::Pin ledGreen, lw::Pin ledRed) : ledGreen(ledGreen), ledRed(ledRed){}
	void init(bool isKeyOn)
	{
		ledGreen.reset();
		ledRed.reset();
		if(isKeyOn)
			state = PDU_STATE::KEY_ON_BUTTON_ALREADY_PRESSED;
		else
			state = PDU_STATE::KEY_OFF;
	}
	PDU_EVENT processTimeOut(bool isKeyOn, bool isButtonPressed)
	{
		PDU_EVENT result = PDU_EVENT::IDLE;
		switch (state) {
			case PDU_STATE::KEY_OFF:
			{
				ledGreen.reset();
				ledRed.reset();
				if(isKeyOn)
				{
					resetBlinkTimer();
					state = PDU_STATE::KEY_ON_EVENT;
					result = PDU_EVENT::KEY_ON_EVENT;
				}
				break;
			}
			case PDU_STATE::KEY_ON_EVENT:
			{
				ledRed.reset();
				if(isKeyOn)
				{
					processBlinkingKeyTurnedOn();
					if(isBlinkKeyOnEnded())
						state = PDU_STATE::KEY_ON;
				}
				else
					state = PDU_STATE::KEY_OFF;
				break;
			}
			case PDU_STATE::KEY_ON:
			{
				ledGreen.set();
				ledRed.reset();
				if(isKeyOn == false)
					state = PDU_STATE::KEY_OFF;
				else if (isButtonPressed)
					state = PDU_STATE::KEY_ON_BUTTON_PRESSED_EVENT;
				break;
			}
			case PDU_STATE::KEY_ON_BUTTON_PRESSED_EVENT:
			{
				result = PDU_EVENT::BUTTON_EVENT;
				ledRed.set();
				state = PDU_STATE::KEY_ON_BUTTON_ALREADY_PRESSED;
				break;
			}
			case PDU_STATE::KEY_ON_BUTTON_ALREADY_PRESSED:
			{
				ledGreen.set();
				ledRed.set();
				if(isKeyOn == false)
					state = PDU_STATE::KEY_OFF;
				break;
			}
			default:
				break;
		}
		return result;
	}
private:
	void resetBlinkTimer()
	{
		blinkTimer_ms = 0;
	}
	void processBlinkingKeyTurnedOn()
	{
		blinkTimer_ms += timeout_ms;
		ledGreen.write((blinkTimer_ms / BLINK_PERIOD_MS) % 2 == 0);
	}
	bool isBlinkKeyOnEnded()
	{
		return blinkTimer_ms > 2 * BLINK_PERIOD_MS * BLINK_QTTY;
	}
};
