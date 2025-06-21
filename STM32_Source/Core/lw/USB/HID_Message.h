#pragma once
#include <cstdint>

namespace lw
{
namespace USB_HID
{

struct KeyboardMessage
{
	uint8_t id;
	uint8_t modifiers;
	uint8_t key1;
	uint8_t key2;
	uint8_t key3;
};

} //namespace USB_HID
} //namespace lw
