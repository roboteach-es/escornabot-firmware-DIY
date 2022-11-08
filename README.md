# Arduino firmware for the Escornabot Brivoi (DIY version)

## GALEGO / CASTELÁN
Se queres, podes empregar [esta guía paso a paso](https://www.roboteach.es/escornabot-firmware/) para instalar o firmware no teu **Escornabot Brivoi DIY**.

## ENGLISH
This is the Arduino firmware to be uploaded to the **Escornabot Brivoi (DIY version)**.

This is a fork of [the orignal version](https://github.com/escornabot/arduino) pre-configured by default for [this specific keypad](https://github.com/mgesteiro/escornakeypad) and with some [adittional fixes](https://github.com/escornabot/arduino/pull/18) and new features too.

More info about the Escornabot at **[escornabot.org](https://escornabot.org)**.

## [NEW] &nbsp;Keypad Auto-Configuration
This version of our **ROBOteach firmware** (**v1.7.0-RT** or later) includes a new feature long awaited, the possibility **to automatically configure the keypad**: tune your Escornabot to your specific [analog]keypad, and forget about it (the values will be permanently stored and retrieved during the start-up). No need to touch the *source-code* (if you don't want 😉).

These are the steps to configure it:

1. **Turn-off** the Escornabot.
2. While **pressing any** of the keypad keys, turn it on again until you start hearing the Escornabot **beeping four times**: this indicates that it is in the *keypad configuration state*.
3. Now click all the keypad keys **in the following order**: *UP*, *LEFT*, *GO*, *RIGHT* and *DOWN*. You'll hear a beep everytime you press one.
4. After that, you'll hear the normal start-up sound: **everything is done!**

If you make any mistake or anything happens during the process, don't worry, you can re-start it all over again: quick & easy.

This procedure should be done **only once whith fresh batteries** in place. The configuration values are stored in the EEPROM and reloaded everytime the Escornabot is turned on. Don't abuse this feature, e.g. when the baterries are low, as it won't help and may even damage the EEPROM (persistent memory), that has limited writing cycles.


## Install instructions

First of all, you need to donwload and uncompress [this firmware zip file](https://github.com/roboteach-es/escornabot-firmware-DIY/archive/refs/heads/stable.zip) somewhere in you computer. Then, follow one of these two alternatives:

### Using the Arduino IDE

1. Download and install the [Arduino IDE](https://www.arduino.cc/en/Main/Software).
2. Open the `Escornabot.ino` file in the `Escornabot` subfolder (inside the downloaded compressed file) with the **Arduino IDE**.
3. Choose the appropiate *Board* (=*Arduino Nano*), *Processor* and *Port* (these are specific for you and your computer) in the *Tools* menu, and finally click the upload button.


### Using PlatformIO (advanced)

You'll need to install [PlatformIO CLI](https://platformio.org/install/cli):

    pip install -U platformio

There is already a project file *platformio.ini* to compile and upload the
firmware to the Atmel AVR platform + Arduino framework for the Arduino Nano
and Arduino Micro boards.

#### Arduino Nano

    # compile firmware and upload firmware to an Arduino Nano:
    pio run -e nano -t upload

#### Arduino Micro

    # compile firmware and upload firmware to an Arduino Micro:
    pio run -e micro -t upload
