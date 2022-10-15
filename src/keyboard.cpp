#include "keyboard.h"

void kbSetup() {
  TrinketKeyboard.begin();
  while (TrinketKeyboard.isConnected() == 0) {
    TrinketKeyboard.poll();
  }
  TrinketKeyboard.typeChar(0);
}

bool isCaps() {
  uint8_t ledState = TrinketKeyboard.getLEDstate();
  return ledState & KB_LED_CAPS;
}

void kbDelay(unsigned long ms) {
  unsigned long start = millis();
  while (millis() - start < ms) {
    TrinketKeyboard.poll();
  }
}

void pressRelease(uint8_t modifiers, uint8_t keycode1) {
  TrinketKeyboard.pressKey(modifiers, keycode1);
  TrinketKeyboard.pressKey(0, 0);
}

void printNumber(int no) {
  if (no < 0) {
    TrinketKeyboard.typeChar('-');
    no = -no;
  }

  short buf[10];
  int i = 0;
  do {
    buf[i++] = no % 10;
    no /= 10;
  } while (no != 0);

  while (i) {
    TrinketKeyboard.typeChar(48 + buf[--i]);
  }
}
