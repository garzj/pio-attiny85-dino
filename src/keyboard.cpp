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
