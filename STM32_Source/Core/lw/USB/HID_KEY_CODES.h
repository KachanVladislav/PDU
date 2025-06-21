#pragma once
/**
 * Adapted from:
 * https://gist.github.com/MightyPork/6da26e382a7ad91b5496ee55fdc73db2
 * Original comment:
	 * USB HID Keyboard scan codes as per USB spec 1.11
	 * plus some additional codes
	 *
	 * Created by MightyPork, 2016
	 * Public domain
	 *
	 * Adapted from:
	 * https://source.android.com/devices/input/keyboard-devices.html
 */
#include <cstdint>

namespace lw
{
namespace HID
{

static constexpr uint8_t KEY_MOD_LCTRL  = 0x01;
static constexpr uint8_t KEY_MOD_LSHIFT = 0x02;
static constexpr uint8_t KEY_MOD_LALT   = 0x04;
static constexpr uint8_t KEY_MOD_LMETA  = 0x08;
static constexpr uint8_t KEY_MOD_RCTRL  = 0x10;
static constexpr uint8_t KEY_MOD_RSHIFT = 0x20;
static constexpr uint8_t KEY_MOD_RALT   = 0x40;
static constexpr uint8_t KEY_MOD_RMETA  = 0x80;

/**
 * Scan codes - last N slots in the HID report (usually 6).
 * 0x00 if no key pressed.
 *
 * If more than N keys are pressed, the HID reports
 * KEY_ERR_OVF in all slots to indicate this condition.
 */

static constexpr uint8_t KEY_NONE = 0x00; // No key pressed
static constexpr uint8_t KEY_ERR_OVF = 0x01; //  Keyboard Error Roll Over - used for all slots if too many keys are pressed ("Phantom key")
// 0x02 //  Keyboard POST Fail
// 0x03 //  Keyboard Error Undefined
static constexpr uint8_t KEY_A = 0x04; // Keyboard a and A
static constexpr uint8_t KEY_B = 0x05; // Keyboard b and B
static constexpr uint8_t KEY_C = 0x06; // Keyboard c and C
static constexpr uint8_t KEY_D = 0x07; // Keyboard d and D
static constexpr uint8_t KEY_E = 0x08; // Keyboard e and E
static constexpr uint8_t KEY_F = 0x09; // Keyboard f and F
static constexpr uint8_t KEY_G = 0x0a; // Keyboard g and G
static constexpr uint8_t KEY_H = 0x0b; // Keyboard h and H
static constexpr uint8_t KEY_I = 0x0c; // Keyboard i and I
static constexpr uint8_t KEY_J = 0x0d; // Keyboard j and J
static constexpr uint8_t KEY_K = 0x0e; // Keyboard k and K
static constexpr uint8_t KEY_L = 0x0f; // Keyboard l and L
static constexpr uint8_t KEY_M = 0x10; // Keyboard m and M
static constexpr uint8_t KEY_N = 0x11; // Keyboard n and N
static constexpr uint8_t KEY_O = 0x12; // Keyboard o and O
static constexpr uint8_t KEY_P = 0x13; // Keyboard p and P
static constexpr uint8_t KEY_Q = 0x14; // Keyboard q and Q
static constexpr uint8_t KEY_R = 0x15; // Keyboard r and R
static constexpr uint8_t KEY_S = 0x16; // Keyboard s and S
static constexpr uint8_t KEY_T = 0x17; // Keyboard t and T
static constexpr uint8_t KEY_U = 0x18; // Keyboard u and U
static constexpr uint8_t KEY_V = 0x19; // Keyboard v and V
static constexpr uint8_t KEY_W = 0x1a; // Keyboard w and W
static constexpr uint8_t KEY_X = 0x1b; // Keyboard x and X
static constexpr uint8_t KEY_Y = 0x1c; // Keyboard y and Y
static constexpr uint8_t KEY_Z = 0x1d; // Keyboard z and Z

static constexpr uint8_t KEY_1 = 0x1e; // Keyboard 1 and !
static constexpr uint8_t KEY_2 = 0x1f; // Keyboard 2 and @
static constexpr uint8_t KEY_3 = 0x20; // Keyboard 3 and #
static constexpr uint8_t KEY_4 = 0x21; // Keyboard 4 and $
static constexpr uint8_t KEY_5 = 0x22; // Keyboard 5 and %
static constexpr uint8_t KEY_6 = 0x23; // Keyboard 6 and ^
static constexpr uint8_t KEY_7 = 0x24; // Keyboard 7 and &
static constexpr uint8_t KEY_8 = 0x25; // Keyboard 8 and *
static constexpr uint8_t KEY_9 = 0x26; // Keyboard 9 and (
static constexpr uint8_t KEY_0 = 0x27; // Keyboard 0 and )

static constexpr uint8_t KEY_ENTER = 0x28; // Keyboard Return (ENTER)
static constexpr uint8_t KEY_ESC = 0x29; // Keyboard ESCAPE
static constexpr uint8_t KEY_BACKSPACE = 0x2a; // Keyboard DELETE (Backspace)
static constexpr uint8_t KEY_TAB = 0x2b; // Keyboard Tab
static constexpr uint8_t KEY_SPACE = 0x2c; // Keyboard Spacebar
static constexpr uint8_t KEY_MINUS = 0x2d; // Keyboard - and _
static constexpr uint8_t KEY_EQUAL = 0x2e; // Keyboard = and +
static constexpr uint8_t KEY_LEFTBRACE = 0x2f; // Keyboard [ and {
static constexpr uint8_t KEY_RIGHTBRACE = 0x30; // Keyboard ] and }
static constexpr uint8_t KEY_BACKSLASH = 0x31; // Keyboard \ and |
static constexpr uint8_t KEY_HASHTILDE = 0x32; // Keyboard Non-US # and ~
static constexpr uint8_t KEY_SEMICOLON = 0x33; // Keyboard ; and :
static constexpr uint8_t KEY_APOSTROPHE = 0x34; // Keyboard ' and "
static constexpr uint8_t KEY_GRAVE = 0x35; // Keyboard ` and ~
static constexpr uint8_t KEY_COMMA = 0x36; // Keyboard , and <
static constexpr uint8_t KEY_DOT = 0x37; // Keyboard . and >
static constexpr uint8_t KEY_SLASH = 0x38; // Keyboard / and ?
static constexpr uint8_t KEY_CAPSLOCK = 0x39; // Keyboard Caps Lock

static constexpr uint8_t KEY_F1 = 0x3a; // Keyboard F1
static constexpr uint8_t KEY_F2 = 0x3b; // Keyboard F2
static constexpr uint8_t KEY_F3 = 0x3c; // Keyboard F3
static constexpr uint8_t KEY_F4 = 0x3d; // Keyboard F4
static constexpr uint8_t KEY_F5 = 0x3e; // Keyboard F5
static constexpr uint8_t KEY_F6 = 0x3f; // Keyboard F6
static constexpr uint8_t KEY_F7 = 0x40; // Keyboard F7
static constexpr uint8_t KEY_F8 = 0x41; // Keyboard F8
static constexpr uint8_t KEY_F9 = 0x42; // Keyboard F9
static constexpr uint8_t KEY_F10 = 0x43; // Keyboard F10
static constexpr uint8_t KEY_F11 = 0x44; // Keyboard F11
static constexpr uint8_t KEY_F12 = 0x45; // Keyboard F12

static constexpr uint8_t KEY_SYSRQ = 0x46; // Keyboard Print Screen
static constexpr uint8_t KEY_SCROLLLOCK = 0x47; // Keyboard Scroll Lock
static constexpr uint8_t KEY_PAUSE = 0x48; // Keyboard Pause
static constexpr uint8_t KEY_INSERT = 0x49; // Keyboard Insert
static constexpr uint8_t KEY_HOME = 0x4a; // Keyboard Home
static constexpr uint8_t KEY_PAGEUP = 0x4b; // Keyboard Page Up
static constexpr uint8_t KEY_DELETE = 0x4c; // Keyboard Delete Forward
static constexpr uint8_t KEY_END = 0x4d; // Keyboard End
static constexpr uint8_t KEY_PAGEDOWN = 0x4e; // Keyboard Page Down
static constexpr uint8_t KEY_RIGHT = 0x4f; // Keyboard Right Arrow
static constexpr uint8_t KEY_LEFT = 0x50; // Keyboard Left Arrow
static constexpr uint8_t KEY_DOWN = 0x51; // Keyboard Down Arrow
static constexpr uint8_t KEY_UP = 0x52; // Keyboard Up Arrow

static constexpr uint8_t KEY_NUMLOCK = 0x53; // Keyboard Num Lock and Clear
static constexpr uint8_t KEY_KPSLASH = 0x54; // Keypad /
static constexpr uint8_t KEY_KPASTERISK = 0x55; // Keypad *
static constexpr uint8_t KEY_KPMINUS = 0x56; // Keypad -
static constexpr uint8_t KEY_KPPLUS = 0x57; // Keypad +
static constexpr uint8_t KEY_KPENTER = 0x58; // Keypad ENTER
static constexpr uint8_t KEY_KP1 = 0x59; // Keypad 1 and End
static constexpr uint8_t KEY_KP2 = 0x5a; // Keypad 2 and Down Arrow
static constexpr uint8_t KEY_KP3 = 0x5b; // Keypad 3 and PageDn
static constexpr uint8_t KEY_KP4 = 0x5c; // Keypad 4 and Left Arrow
static constexpr uint8_t KEY_KP5 = 0x5d; // Keypad 5
static constexpr uint8_t KEY_KP6 = 0x5e; // Keypad 6 and Right Arrow
static constexpr uint8_t KEY_KP7 = 0x5f; // Keypad 7 and Home
static constexpr uint8_t KEY_KP8 = 0x60; // Keypad 8 and Up Arrow
static constexpr uint8_t KEY_KP9 = 0x61; // Keypad 9 and Page Up
static constexpr uint8_t KEY_KP0 = 0x62; // Keypad 0 and Insert
static constexpr uint8_t KEY_KPDOT = 0x63; // Keypad . and Delete

static constexpr uint8_t KEY_102ND = 0x64; // Keyboard Non-US \ and |
static constexpr uint8_t KEY_COMPOSE = 0x65; // Keyboard Application
static constexpr uint8_t KEY_POWER = 0x66; // Keyboard Power
static constexpr uint8_t KEY_KPEQUAL = 0x67; // Keypad =

static constexpr uint8_t KEY_F13 = 0x68; // Keyboard F13
static constexpr uint8_t KEY_F14 = 0x69; // Keyboard F14
static constexpr uint8_t KEY_F15 = 0x6a; // Keyboard F15
static constexpr uint8_t KEY_F16 = 0x6b; // Keyboard F16
static constexpr uint8_t KEY_F17 = 0x6c; // Keyboard F17
static constexpr uint8_t KEY_F18 = 0x6d; // Keyboard F18
static constexpr uint8_t KEY_F19 = 0x6e; // Keyboard F19
static constexpr uint8_t KEY_F20 = 0x6f; // Keyboard F20
static constexpr uint8_t KEY_F21 = 0x70; // Keyboard F21
static constexpr uint8_t KEY_F22 = 0x71; // Keyboard F22
static constexpr uint8_t KEY_F23 = 0x72; // Keyboard F23
static constexpr uint8_t KEY_F24 = 0x73; // Keyboard F24

static constexpr uint8_t KEY_OPEN = 0x74; // Keyboard Execute
static constexpr uint8_t KEY_HELP = 0x75; // Keyboard Help
static constexpr uint8_t KEY_PROPS = 0x76; // Keyboard Menu
static constexpr uint8_t KEY_FRONT = 0x77; // Keyboard Select
static constexpr uint8_t KEY_STOP = 0x78; // Keyboard Stop
static constexpr uint8_t KEY_AGAIN = 0x79; // Keyboard Again
static constexpr uint8_t KEY_UNDO = 0x7a; // Keyboard Undo
static constexpr uint8_t KEY_CUT = 0x7b; // Keyboard Cut
static constexpr uint8_t KEY_COPY = 0x7c; // Keyboard Copy
static constexpr uint8_t KEY_PASTE = 0x7d; // Keyboard Paste
static constexpr uint8_t KEY_FIND = 0x7e; // Keyboard Find
static constexpr uint8_t KEY_MUTE = 0x7f; // Keyboard Mute
static constexpr uint8_t KEY_VOLUMEUP = 0x80; // Keyboard Volume Up
static constexpr uint8_t KEY_VOLUMEDOWN = 0x81; // Keyboard Volume Down
// 0x82  Keyboard Locking Caps Lock
// 0x83  Keyboard Locking Num Lock
// 0x84  Keyboard Locking Scroll Lock
static constexpr uint8_t KEY_KPCOMMA = 0x85; // Keypad Comma
// 0x86  Keypad Equal Sign
static constexpr uint8_t KEY_RO = 0x87; // Keyboard International1
static constexpr uint8_t KEY_KATAKANAHIRAGANA = 0x88; // Keyboard International2
static constexpr uint8_t KEY_YEN = 0x89; // Keyboard International3
static constexpr uint8_t KEY_HENKAN = 0x8a; // Keyboard International4
static constexpr uint8_t KEY_MUHENKAN = 0x8b; // Keyboard International5
static constexpr uint8_t KEY_KPJPCOMMA = 0x8c; // Keyboard International6
// 0x8d  Keyboard International7
// 0x8e  Keyboard International8
// 0x8f  Keyboard International9
static constexpr uint8_t KEY_HANGEUL = 0x90; // Keyboard LANG1
static constexpr uint8_t KEY_HANJA = 0x91; // Keyboard LANG2
static constexpr uint8_t KEY_KATAKANA = 0x92; // Keyboard LANG3
static constexpr uint8_t KEY_HIRAGANA = 0x93; // Keyboard LANG4
static constexpr uint8_t KEY_ZENKAKUHANKAKU = 0x94; // Keyboard LANG5
// 0x95  Keyboard LANG6
// 0x96  Keyboard LANG7
// 0x97  Keyboard LANG8
// 0x98  Keyboard LANG9
// 0x99  Keyboard Alternate Erase
// 0x9a  Keyboard SysReq/Attention
// 0x9b  Keyboard Cancel
// 0x9c  Keyboard Clear
// 0x9d  Keyboard Prior
// 0x9e  Keyboard Return
// 0x9f  Keyboard Separator
// 0xa0  Keyboard Out
// 0xa1  Keyboard Oper
// 0xa2  Keyboard Clear/Again
// 0xa3  Keyboard CrSel/Props
// 0xa4  Keyboard ExSel

// 0xb0  Keypad 00
// 0xb1  Keypad 000
// 0xb2  Thousands Separator
// 0xb3  Decimal Separator
// 0xb4  Currency Unit
// 0xb5  Currency Sub-unit
static constexpr uint8_t KEY_KPLEFTPAREN = 0xb6; // Keypad (
static constexpr uint8_t KEY_KPRIGHTPAREN = 0xb7; // Keypad )
// 0xb8  Keypad {
// 0xb9  Keypad }
// 0xba  Keypad Tab
// 0xbb  Keypad Backspace
// 0xbc  Keypad A
// 0xbd  Keypad B
// 0xbe  Keypad C
// 0xbf  Keypad D
// 0xc0  Keypad E
// 0xc1  Keypad F
// 0xc2  Keypad XOR
// 0xc3  Keypad ^
// 0xc4  Keypad %
// 0xc5  Keypad <
// 0xc6  Keypad >
// 0xc7  Keypad &
// 0xc8  Keypad &&
// 0xc9  Keypad |
// 0xca  Keypad ||
// 0xcb  Keypad :
// 0xcc  Keypad #
// 0xcd  Keypad Space
// 0xce  Keypad @
// 0xcf  Keypad !
// 0xd0  Keypad Memory Store
// 0xd1  Keypad Memory Recall
// 0xd2  Keypad Memory Clear
// 0xd3  Keypad Memory Add
// 0xd4  Keypad Memory Subtract
// 0xd5  Keypad Memory Multiply
// 0xd6  Keypad Memory Divide
// 0xd7  Keypad +/-
// 0xd8  Keypad Clear
// 0xd9  Keypad Clear Entry
// 0xda  Keypad Binary
// 0xdb  Keypad Octal
// 0xdc  Keypad Decimal
// 0xdd  Keypad Hexadecimal

static constexpr uint8_t KEY_LEFTCTRL = 0xe0; // Keyboard Left Control
static constexpr uint8_t KEY_LEFTSHIFT = 0xe1; // Keyboard Left Shift
static constexpr uint8_t KEY_LEFTALT = 0xe2; // Keyboard Left Alt
static constexpr uint8_t KEY_LEFTMETA = 0xe3; // Keyboard Left GUI
static constexpr uint8_t KEY_RIGHTCTRL = 0xe4; // Keyboard Right Control
static constexpr uint8_t KEY_RIGHTSHIFT = 0xe5; // Keyboard Right Shift
static constexpr uint8_t KEY_RIGHTALT = 0xe6; // Keyboard Right Alt
static constexpr uint8_t KEY_RIGHTMETA = 0xe7; // Keyboard Right GUI

static constexpr uint8_t KEY_MEDIA_PLAYPAUSE = 0xe8;
static constexpr uint8_t KEY_MEDIA_STOPCD = 0xe9;
static constexpr uint8_t KEY_MEDIA_PREVIOUSSONG = 0xea;
static constexpr uint8_t KEY_MEDIA_NEXTSONG = 0xeb;
static constexpr uint8_t KEY_MEDIA_EJECTCD = 0xec;
static constexpr uint8_t KEY_MEDIA_VOLUMEUP = 0xed;
static constexpr uint8_t KEY_MEDIA_VOLUMEDOWN = 0xee;
static constexpr uint8_t KEY_MEDIA_MUTE = 0xef;
static constexpr uint8_t KEY_MEDIA_WWW = 0xf0;
static constexpr uint8_t KEY_MEDIA_BACK = 0xf1;
static constexpr uint8_t KEY_MEDIA_FORWARD = 0xf2;
static constexpr uint8_t KEY_MEDIA_STOP = 0xf3;
static constexpr uint8_t KEY_MEDIA_FIND = 0xf4;
static constexpr uint8_t KEY_MEDIA_SCROLLUP = 0xf5;
static constexpr uint8_t KEY_MEDIA_SCROLLDOWN = 0xf6;
static constexpr uint8_t KEY_MEDIA_EDIT = 0xf7;
static constexpr uint8_t KEY_MEDIA_SLEEP = 0xf8;
static constexpr uint8_t KEY_MEDIA_COFFEE = 0xf9;
static constexpr uint8_t KEY_MEDIA_REFRESH = 0xfa;
static constexpr uint8_t KEY_MEDIA_CALC = 0xfb;


} //namespace HIDKeybordKeys
} //namespace lw


//TODO Might be used - Comment
//thaolt commented on Nov 13, 2021
//Thank you for the sharing.
//
//I want to share this array in case of anyone needed
//
//#include "usb_hid_keys.h"
//
//const char ascii_to_hid_key_map[95][2] = {
//    {0, KEY_SPACE}, {KEY_MOD_LSHIFT, KEY_1}, {KEY_MOD_LSHIFT, KEY_APOSTROPHE},
//    {KEY_MOD_LSHIFT, KEY_3}, {KEY_MOD_LSHIFT, KEY_4}, {KEY_MOD_LSHIFT, KEY_5},
//    {KEY_MOD_LSHIFT, KEY_7}, {0, KEY_APOSTROPHE}, {KEY_MOD_LSHIFT, KEY_9},
//    {KEY_MOD_LSHIFT, KEY_0}, {KEY_MOD_LSHIFT, KEY_8}, {KEY_MOD_LSHIFT, KEY_EQUAL},
//    {0, KEY_COMMA}, {0, KEY_MINUS}, {0, KEY_DOT}, {0, KEY_SLASH}, {0, KEY_0},
//    {0, KEY_1}, {0, KEY_2}, {0, KEY_3}, {0, KEY_4}, {0, KEY_5}, {0, KEY_6},
//    {0, KEY_7}, {0, KEY_8}, {0, KEY_9}, {KEY_MOD_LSHIFT, KEY_SEMICOLON},
//    {0, KEY_SEMICOLON}, {KEY_MOD_LSHIFT, KEY_COMMA}, {0, KEY_EQUAL},
//    {KEY_MOD_LSHIFT, KEY_DOT}, {KEY_MOD_LSHIFT, KEY_SLASH}, {KEY_MOD_LSHIFT, KEY_2},
//    {KEY_MOD_LSHIFT, KEY_A}, {KEY_MOD_LSHIFT, KEY_B}, {KEY_MOD_LSHIFT, KEY_C},
//    {KEY_MOD_LSHIFT, KEY_D}, {KEY_MOD_LSHIFT, KEY_E}, {KEY_MOD_LSHIFT, KEY_F},
//    {KEY_MOD_LSHIFT, KEY_G}, {KEY_MOD_LSHIFT, KEY_H}, {KEY_MOD_LSHIFT, KEY_I},
//    {KEY_MOD_LSHIFT, KEY_J}, {KEY_MOD_LSHIFT, KEY_K}, {KEY_MOD_LSHIFT, KEY_L},
//    {KEY_MOD_LSHIFT, KEY_M}, {KEY_MOD_LSHIFT, KEY_N}, {KEY_MOD_LSHIFT, KEY_O},
//    {KEY_MOD_LSHIFT, KEY_P}, {KEY_MOD_LSHIFT, KEY_Q}, {KEY_MOD_LSHIFT, KEY_R},
//    {KEY_MOD_LSHIFT, KEY_S}, {KEY_MOD_LSHIFT, KEY_T}, {KEY_MOD_LSHIFT, KEY_U},
//    {KEY_MOD_LSHIFT, KEY_V}, {KEY_MOD_LSHIFT, KEY_W}, {KEY_MOD_LSHIFT, KEY_X},
//    {KEY_MOD_LSHIFT, KEY_Y}, {KEY_MOD_LSHIFT, KEY_Z}, {0, KEY_LEFTBRACE},
//    {0, KEY_BACKSLASH}, {0, KEY_RIGHTBRACE}, {KEY_MOD_LSHIFT, KEY_6},
//    {KEY_MOD_LSHIFT, KEY_MINUS}, {0, KEY_GRAVE}, {0, KEY_A}, {0, KEY_B},
//    {0, KEY_C}, {0, KEY_D}, {0, KEY_E}, {0, KEY_F}, {0, KEY_G}, {0, KEY_H},
//    {0, KEY_I}, {0, KEY_J}, {0, KEY_K}, {0, KEY_L}, {0, KEY_M}, {0, KEY_N},
//    {0, KEY_O}, {0, KEY_P}, {0, KEY_Q}, {0, KEY_R}, {0, KEY_S}, {0, KEY_T},
//    {0, KEY_U}, {0, KEY_V}, {0, KEY_W}, {0, KEY_X}, {0, KEY_Y}, {0, KEY_Z},
//    {KEY_MOD_LSHIFT, KEY_LEFTBRACE}, {KEY_MOD_LSHIFT, KEY_BACKSLASH},
//    {KEY_MOD_LSHIFT, KEY_RIGHTBRACE}, {KEY_MOD_LSHIFT, KEY_GRAVE},
//};
//Example usage
//
//void hid_sendch(uint8_t c)
//{
//    uint8_t buffer[8] = {0};
//
//    if (c > 127) return;
//    if (c < 32) return;
//
//    c -= 32; // offset ignore the first 32 symbols in ascii table
//
//    buffer[0] = ascii_to_hid_key_map[c][0];
//    buffer[2] = ascii_to_hid_key_map[c][1];
//
//    FILE* f = fopen("/dev/hidg0", "wb");
//    fwrite(buffer, sizeof (char), 8, f);
//    fclose(f);
//
//    usleep(10000);
//
//    buffer[0] = 0;
//    buffer[2]= 0;
//    f = fopen("/dev/hidg0", "wb");
//    fwrite(buffer, sizeof (char), 8, f);
//    fclose(f);
//
//    usleep(50000);
//}
//void hid_sendstr(char* str)
//{
//    uint8_t l = strlen(str);
//    for (uint8_t i = 0; i < l; i++) {
//        hid_sendch(str[i]);
//    }
//}
//hid_sendstr("Hello World!");
