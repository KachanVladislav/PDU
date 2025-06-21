#pragma once
#include "stm32f1xx_hal.h"
#include <usbd_hid.h>
#include "usbd_ctlreq.h"

namespace lw
{

class USB_HID_Stm32Helper
{
public:
	static bool isReady(USBD_HandleTypeDef  *pdev)
	{
		USBD_HID_HandleTypeDef* hhid = (USBD_HID_HandleTypeDef *)pdev->pClassData;
		if (pdev->dev_state == USBD_STATE_CONFIGURED)
			if (hhid->state == HID_IDLE)
				return true;
		return false;
	}

	static bool isReadyBeforeTimeout(USBD_HandleTypeDef  *pdev, uint32_t timeOut_ms)
	{
		for(uint32_t i = 0; i < timeOut_ms; i++)
		{
			if(USB_HID_Stm32Helper::isReady(pdev))
				return true;
			HAL_Delay(1);
		}
		return false;
	}
};

}//namespace lw
