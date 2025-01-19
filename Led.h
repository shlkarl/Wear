#pragma once
#include <Adafruit_NeoPixel.h>

  Adafruit_NeoPixel strip(60, 21, NEO_GRB + NEO_KHZ800);

class LED{
  int tmp = 0;
  public:
  LED();
  void light(int c);
};
