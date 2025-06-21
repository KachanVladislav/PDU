#pragma once

namespace lw
{

class Pin
{
	LW_PIN_FIELDS
public:
	LW_PIN_CONSTRUCTOR

	bool isSet()
	{
		return LW_PIN_IS_SET
	}

	void write(bool state)
	{
		LW_PIN_WRITE
	}

	void set()
	{
		write(true);
	}

	void reset()
	{
		write(false);
	}

	void toogle()
	{
		LW_PIN_TOOGLE
	}
};

}//namespace lw
