#pragma once
#include "OneWire.h" 
#include "DallasTemperature.h"
OneWire  ds(5);//
DallasTemperature sensors(&ds); 


class TERMAL{
  int heatFront, heatBack, heatLeft, heatRight;
  byte type_s = 0;
  DeviceAddress ds0 = { 0x28, 0xC2, 0xDB, 0x5E, 0x00, 0x00, 0x00, 0x0C };
  DeviceAddress ds1 = { 0x28, 0x90, 0x8C, 0x84, 0x70, 0x22, 0x08, 0xEF };
  DeviceAddress ds2 = { 0x28, 0x9A, 0xE1, 0x2A, 0x00, 0x00, 0x00, 0x1C };
 public:
  TERMAL();
  
  void SetFront(int f);
  void HeatingFront();
  float GetFront();

  void SetBack(int b);
  void HeatingBack();
  float GetBack();

  void SetLeft(int l);
  void HeatingLeft();
  float GetLeft();

  void SetRight(int r);
  void HeatingRight();
  float GetRight();

  
  void Cooling(char c);
};
