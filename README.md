# pio-attiny85-dino

A little dino game for the ATTiny85 USB using platform io.

![Game preview](./game.gif)

The microcontroller simulates a keyboard and uses the CAPS lock LED signal to receive input.

This project was tested using Windows `notepad.exe`, keyboard combinations may not move the cursor correctly anywhere else.

## Setup

- Buy the microcontroller: https://amzn.eu/d/fbsHuZK
- Install neccessary drivers: https://github.com/digistump/DigistumpArduino/releases/download/1.6.7/Digistump.Drivers.zip
- `git clone https://github.com/garzj/pio-attiny85-dino.git`
- Install (platform io core)[https://docs.platformio.org/en/latest/core/installation/index.html]
- `cd pio-attiny85-dino`
- [Optional] Configure VS Code for platform io: `pio init --ide=vscode`
- Upload to your microcontroller: `pio run --target upload`

## How to play

- Plug the ATTiny85 into any PC running Windows
- Use an US keyboard layout
- Open `notepad.exe`
- Make sure it's in focus and plug in the ATTiny85
