// KeypadLeds.cpp

#include "KeypadLeds.h"
#include "Enums.h"
#include "Arduino.h"
#include "EventManager.h"

//////////////////////////////////////////////////////////////////////

extern EventManager* EVENTS;

//////////////////////////////////////////////////////////////////////

KeypadLeds::KeypadLeds(const Config* config)
{
    this->_config = config;
}

//////////////////////////////////////////////////////////////////////

void KeypadLeds::init()
{
    pinMode(_config->pin_led_up, OUTPUT);
    pinMode(_config->pin_led_right, OUTPUT);
    pinMode(_config->pin_led_down, OUTPUT);
    pinMode(_config->pin_led_left, OUTPUT);
    pinMode(_config->pin_led_go, OUTPUT);

    EVENTS->add(this);
}

//////////////////////////////////////////////////////////////////////

void KeypadLeds::setLed(uint8_t button, bool light)
{
    uint8_t pin = 255;

    switch (button) {

        case BUTTON_UP:
            pin = _config->pin_led_up;
            break;

        case BUTTON_RIGHT:
            pin = _config->pin_led_right;
            break;

        case BUTTON_DOWN:
            pin = _config->pin_led_down;
            break;

        case BUTTON_LEFT:
            pin = _config->pin_led_left;
            break;

        case BUTTON_GO:
            pin = _config->pin_led_go;
            break;
    }

    if (pin != 255)
    {
        digitalWrite(pin, light ? HIGH : LOW);
    }
}

//////////////////////////////////////////////////////////////////////

BUTTON KeypadLeds::_mov2btn(MOVE move)
{
    switch (move) {

        case MOVE_FORWARD:
            return BUTTON_UP;
            // break;

        case MOVE_RIGHT:
            return BUTTON_RIGHT;
            // break;

        case MOVE_BACKWARD:
            return BUTTON_DOWN;
            // break;

        case MOVE_LEFT:
            return BUTTON_LEFT;
            // break;
    }

    return BUTTON_NONE;
}

//////////////////////////////////////////////////////////////////////

// EOF
