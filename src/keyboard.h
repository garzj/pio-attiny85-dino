#pragma once
#include <Arduino.h>
#include <TrinketKeyboard.h>

void kbSetup();

bool isCaps();

void pressRelease(uint8_t, uint8_t);

void printNumber(int);

void kbDelay(unsigned long);
