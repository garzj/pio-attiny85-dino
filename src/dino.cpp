#include "dino.h"
#include "keyboard.h"

bool isJumping = false;

bool dinoJumping() {
  return isJumping;
}

bool runSwitch = false;
void dinoPrint() {
  TrinketKeyboard.typeChar(isJumping ? '*' : (runSwitch ? 'R' : 'D'));
  runSwitch = !runSwitch;
  pressRelease(0, KEYCODE_ARROW_LEFT);
}

void dinoDel() {
  TrinketKeyboard.pressKey(0, KEYCODE_DELETE);
  TrinketKeyboard.pressKey(0, 0);
}

void dinoJump(bool jumping) {
  if (isJumping == jumping) return;

  isJumping = jumping;

  dinoDel();
  dinoPrint();
}
