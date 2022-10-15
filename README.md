# pio-attiny85-dino

A little dino game for the ATTiny85 USB using platform io.

## Setup

- Buy the microcontroller: https://amzn.eu/d/fbsHuZK
- Install neccessary drivers: https://github.com/digistump/DigistumpArduino/releases/download/1.6.7/Digistump.Drivers.zip
- `git clone https://github.com/garzj/pio-attiny85-dino.git`
- Install (platform io core)[https://docs.platformio.org/en/latest/core/installation/index.html]
- `cd pio-attiny85-dino`
- [Optional] Configure VS Code for platform io: `pio init --ide=vscode`
- Upload to your microcontroller: `pio run --target upload`

## How to play

- Open `notepad.exe` or some other editor
- Make sure it's in focus and plug in the ATTiny85
