#pragma once
#include "OneWire.h" 
#include "DallasTemperature.h"
OneWire  ds(4);//
DallasTemperature sensors(&ds); 


class TERMAL{
  int heatFront, heatBack, heatLeft, heatRight;
  byte type_s = 0;
  DeviceAddress ds0 = { 0x28, 0x97, 0xC7, 0x6B, 0x0, 0x0, 0x0, 0x5D };
  DeviceAddress ds1 = { 0x28, 0x37, 0x29, 0x83, 0x0, 0x0, 0x0, 0x2C };
  DeviceAddress ds2 = { 0x28, 0xD5, 0x2E, 0x6B, 0x0, 0x0, 0x0, 0x6F };
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
