#include "fields.h"

const int fieldsLen = 50;
char fields[fieldsLen];

const char minObDist = 5;
const char obChance = 3; // 1 in x, that an obstacle spawns

const char FIELD_GND = '_';
const char FIELD_OB = '.';

const int DINO_OFF = 24;

int curX;
int lastOb;
char nextField() {
  char c = FIELD_GND;
  if (curX > lastOb + minObDist) {
    if (rand() % obChance == 0) {
      lastOb = curX;
      c = FIELD_OB;
    }
  }
  curX++;
  return c;
}

// This function always leaves the cursor immediatly before the dino
void fieldSetup() {
  curX = 0;
  lastOb = 25;

  for (int x = 0; x < fieldsLen; x++) {
    fields[x] = nextField();

    if (x == DINO_OFF) {
      TrinketKeyboard.typeChar(' ');
      dinoPrint();
      pressRelease(0, KEYCODE_ARROW_RIGHT);
    } else {
      TrinketKeyboard.typeChar(fields[x]);
    }
  }

  pressRelease(KEYCODE_MOD_LEFT_CONTROL, KEYCODE_ARROW_LEFT);
}

// This function always leaves the cursor immediatly before the dino
void fieldStep() {
  // Move fields array
  memmove(fields, fields + 1, fieldsLen - 1);
  fields[fieldsLen - 1] = nextField();

  // Insert new at end
  pressRelease(0, KEYCODE_END);
  TrinketKeyboard.typeChar(fields[fieldsLen - 1]);

  // Delete from start
  pressRelease(0, KEYCODE_HOME);
  pressRelease(0, KEYCODE_DELETE);

  // Move dino
  pressRelease(KEYCODE_MOD_LEFT_CONTROL, KEYCODE_ARROW_RIGHT);
  pressRelease(0, KEYCODE_ARROW_RIGHT);

  pressRelease(0, KEYCODE_DELETE);

  for (int i = 0; i < 2; i++) {
    pressRelease(0, KEYCODE_ARROW_LEFT);
  }
  TrinketKeyboard.typeChar(fields[DINO_OFF - 1]);

  pressRelease(0, KEYCODE_ARROW_RIGHT);
}

bool isCurObstacle() {
  return fields[DINO_OFF] == FIELD_OB;
}

int getScore() {
  return curX - fieldsLen;
}
