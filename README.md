# Arduino firmware for the Escornabot Brivoi (DIY version)

This is the Arduino firmware to be uploaded to the **Escornabot Brivoi (DIY version)**.

This is a fork of [the orignal version](https://github.com/escornabot/arduino) tuned by default for [this specific keypad](https://github.com/mgesteiro/escornakeypad) and with some [adittional fixes](https://github.com/escornabot/arduino/pull/18) and small changes too.

More info about the Escornabot at **[escornabot.org](https://escornabot.org)**.


## Install instructions

First of all, you need to donwload and uncompress [this firmware zip file](https://github.com/roboteach-es/escornabot-firmware-DIY/archive/refs/tags/v1.6.2-RT.zip) somewhere in you computer. Then, follow one of these two alternatives:

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
