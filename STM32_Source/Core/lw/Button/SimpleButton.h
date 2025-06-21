#pragma once
#include "lw/Pin/Pin.h"

namespace lw
{

enum class SimpleButtonState
{
	UNPRESSED,
	PRESSED,
	EVENT_PRESSED,
	EVENT_RELEASED
};

class SimpleButton
{
	lw::Pin pin;
	const uint32_t filterTime = 3;
	SimpleButtonState state;
	uint32_t currentFilterTime = 0;
public:
	SimpleButton(lw::Pin pin): pin(pin) {}
	SimpleButton(lw::Pin pin, const uint32_t filterTime): pin(pin), filterTime(filterTime) {}

	SimpleButtonState procesTimeout()
	{
		switch(state)
		{
			case SimpleButtonState::UNPRESSED:
			{
				if(pin.isSet())
					currentFilterTime++;
				else
					currentFilterTime = 0;
				if(currentFilterTime >= filterTime)
				{
					currentFilterTime = 0;
					state = SimpleButtonState::EVENT_PRESSED;
				}
				break;
			}
			case SimpleButtonState::PRESSED:
			{
				if(pin.isSet() == false)
					currentFilterTime++;
				else
					currentFilterTime = 0;
				if(currentFilterTime >= filterTime)
				{
					currentFilterTime = 0;
					state = SimpleButtonState::EVENT_RELEASED;
				}
				break;
			}
			case SimpleButtonState::EVENT_PRESSED:
			{
				if(pin.isSet())
					state = SimpleButtonState::PRESSED;
				else
					state = SimpleButtonState::EVENT_RELEASED;
				break;
			}
			case SimpleButtonState::EVENT_RELEASED:
			{
				if(pin.isSet() == false)
					state = SimpleButtonState::UNPRESSED;
				else
					state = SimpleButtonState::EVENT_PRESSED;
				break;
			}
		}
		return state;
	}
};
} //namespace lw

