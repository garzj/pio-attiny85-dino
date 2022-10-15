#include "dino.h"
#include "fields.h"
#include "keyboard.h"
#include <Arduino.h>

void gameStart();

const unsigned long moveTime = 200;
unsigned long lastMoveTime;

const unsigned long dinoReprintTime = 250;
unsigned long lastDinoReprint;

bool prevCaps;
unsigned long jumpStart;
const int jumpDur = 500;

void setup() {
  randomSeed(millis());
  kbSetup();

  TrinketKeyboard.print("Welcome to Dinospark!\n\nUse CAPS to jump.\n\n");
  kbDelay(2500);

  gameStart();
}

void gameStart() {
  prevCaps = isCaps();

  fieldSetup();
  lastMoveTime = millis();
  lastDinoReprint = millis();
}

void gameOver() {
  pressRelease(0, KEYCODE_END);

  TrinketKeyboard.print("\n\n\nOh no... You lost :(\n\nYour score: ");
  printNumber(getScore());

  TrinketKeyboard.print("\n\nPress CAPS to reset: ");
  for (int timesLeft = 3; timesLeft > 0; timesLeft--) {
    printNumber(timesLeft);
    bool lastCaps = isCaps();
    while (lastCaps == isCaps()) {
      TrinketKeyboard.poll();
    }
    pressRelease(0, KEYCODE_BACKSPACE);
  }
  printNumber(0);
  kbDelay(500);

  TrinketKeyboard.pressKey(KEYCODE_MOD_LEFT_CONTROL, KEYCODE_A);
  pressRelease(0, KEYCODE_DELETE);

  gameStart();
}

void loop() {
  // Move
  unsigned long frameTime = millis();

  if (frameTime - lastMoveTime >= moveTime) {
    lastMoveTime += moveTime;

    fieldStep();
  }

  // Collision
  if (!dinoJumping() && isCurObstacle()) {
    gameOver();
    return;
  }

  // Keypress
  bool jump = false;
  bool caps = isCaps();
  jump = prevCaps != caps;
  prevCaps = caps;

  if (!dinoJumping() && jump) {
    dinoJump(true);
    jumpStart = frameTime;
  }

  if (dinoJumping() && frameTime - jumpStart >= jumpDur) {
    dinoJump(false);
  }

  if (frameTime - lastDinoReprint >= dinoReprintTime) {
    dinoDel();
    dinoPrint();
    lastDinoReprint = frameTime;
  }

  TrinketKeyboard.poll();
}
