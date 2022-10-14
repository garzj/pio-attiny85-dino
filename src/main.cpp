#include "keyboard.h"
#include <Arduino.h>
#include <TrinketKeyboard.h>

bool prevCaps;

void setup() {
  kbSetup();

  prevCaps = isCaps();
}

void loop() {
  bool jump = false;
  bool caps = isCaps();
  jump = prevCaps != caps;
  prevCaps = caps;

  if (jump) {
    TrinketKeyboard.println("jump");
  }

  TrinketKeyboard.poll();
}
