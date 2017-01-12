// Escornabot.h
/*

Copyright (C) 2014-2017 Escornabot - http://escornabot.com

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
USA.

See LICENSE.txt for details

*/

#ifndef _ESCORNABOT_H
#define _ESCORNABOT_H

#include <Arduino.h>
#include "Configuration.h"
#include "Enums.h"
#include "MoveList.h"
#include "Engine.h"
#include "Keypad.h"
#include "EventManager.h"

#if defined(ENGINE_TYPE_STEPPERS)

    #include "EngineSteppers.h"
    const EngineSteppers::Config ENGINE_CONFIG = {
        motor_left_in1: STEPPERS_MOTOR_LEFT_IN1,
        motor_left_in2: STEPPERS_MOTOR_LEFT_IN2,
        motor_left_in3: STEPPERS_MOTOR_LEFT_IN3,
        motor_left_in4: STEPPERS_MOTOR_LEFT_IN4,
        motor_right_in1: STEPPERS_MOTOR_RIGHT_IN1,
        motor_right_in2: STEPPERS_MOTOR_RIGHT_IN2,
        motor_right_in3: STEPPERS_MOTOR_RIGHT_IN3,
        motor_right_in4: STEPPERS_MOTOR_RIGHT_IN4,
        steps_per_second: STEPPERS_STEPS_PER_SECOND,
        line_steps: STEPPERS_LINE_STEPS,
        turn_steps: STEPPERS_TURN_STEPS,
    };
    EngineSteppers ENGINE_INSTANCE (&ENGINE_CONFIG);
    Engine* ENGINE = (Engine*) &ENGINE_INSTANCE;

#endif

#if defined(BUTTONS_DIGITAL)

    // digital button set
    #include "KeypadDigital.h"
    const KeypadDigital::Config BS_CONFIG = {
        pin_button_up: BS_DIGITAL_UP,
        pin_button_right: BS_DIGITAL_RIGHT,
        pin_button_down: BS_DIGITAL_DOWN,
        pin_button_left: BS_DIGITAL_LEFT,
        pin_button_go: BS_DIGITAL_GO,
        pin_button_reset: BS_DIGITAL_RESET,
    };
    KeypadDigital BUTTONS_INSTANCE (&BS_CONFIG);
    Keypad* BUTTONS = (Keypad*) &BUTTONS_INSTANCE;
    #define USE_BUTTONS true

#elif defined(BUTTONS_ANALOG)

    // analog keypad
    #include "KeypadAnalog.h"
    const KeypadAnalog::Config BS_CONFIG = {
        pin_keypad: BS_ANALOG_PIN,
        pullup: (BS_ANALOG_WIRES == 3 ? false : true),
        val_btn_up: BS_ANALOG_VALUE_UP,
        val_btn_right: BS_ANALOG_VALUE_RIGHT,
        val_btn_down: BS_ANALOG_VALUE_DOWN,
        val_btn_left: BS_ANALOG_VALUE_LEFT,
        val_btn_go: BS_ANALOG_VALUE_GO,
        val_btn_reset: BS_ANALOG_VALUE_RESET,
    };
    KeypadAnalog BUTTONS_INSTANCE (&BS_CONFIG);
    Keypad* BUTTONS = (Keypad*) &BUTTONS_INSTANCE;
    #define USE_BUTTONS true

#endif // Button set

#if defined(USE_BLUETOOTH)

    // default Serial port
    #ifndef BLUETOOTH_SERIAL
        #define BLUETOOTH_SERIAL Serial
    #endif

    #include "Bluetooth.h"
    const Bluetooth::Config BT_CONFIG = {
        serial: &(BLUETOOTH_SERIAL),
        bauds: BLUETOOTH_BAUDS,
    };
    Bluetooth BLUETOOTH_INSTANCE (&BT_CONFIG);
    Bluetooth* BLUETOOTH = &BLUETOOTH_INSTANCE;

#endif // Bluetooth


#if USE_BUZZER
    #include "Buzzer.h"
    Buzzer BUZZER = Buzzer(BUZZER_PIN);
#endif


#if USE_SIMPLE_LED
    #include "SimpleLed.h"
    SimpleLed SIMPLE_LED = SimpleLed(SIMPLE_LED_PIN);
#endif


#if USE_LEDS_KEYPAD
    #include "LedsKeypad.h"
    const LedsKeypad::Config KEYPAD_LEDS_CONFIG = {
        pin_led_up: KEYPAD_LED_PIN_UP,
        pin_led_right: KEYPAD_LED_PIN_RIGHT,
        pin_led_down: KEYPAD_LED_PIN_DOWN,
        pin_led_left: KEYPAD_LED_PIN_LEFT,
        pin_led_go: KEYPAD_LED_PIN_GO,
    };
    LedsKeypad KEYPAD_LEDS = LedsKeypad(&KEYPAD_LEDS_CONFIG);
#endif

// event manager
EventManager EVENTS_INSTANCE;
EventManager* EVENTS = &EVENTS_INSTANCE;

// program
MoveList PROGRAM_INSTANCE;
MoveList* PROGRAM = &PROGRAM_INSTANCE;


#endif // _ESCORNABOT_H

// EOF
