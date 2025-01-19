#include "Termal.h"

TERMAL::TERMAL(){pinMode(6,OUTPUT);pinMode(7,OUTPUT);pinMode(8,OUTPUT);pinMode(9,OUTPUT);pinMode(21, OUTPUT);
                 heatFront = 0, heatBack = 0, heatLeft = 0, heatRight = 0;}


void TERMAL::SetFront(int f){heatFront = f;}
void TERMAL::HeatingFront(){ if(GetFront() < heatFront) digitalWrite(6,HIGH);  else digitalWrite(6,LOW);}
float TERMAL::GetFront() {sensors.requestTemperatures(); return sensors.getTempC(ds0);}


void TERMAL::SetBack(int b){heatBack = b;}
void TERMAL::HeatingBack(){ if(GetBack() < heatBack) digitalWrite(7,HIGH); else digitalWrite(7,LOW);}
float TERMAL::GetBack() {sensors.requestTemperatures(); return sensors.getTempC(ds1);}


void TERMAL::SetLeft(int l){heatLeft = l;}
void TERMAL::HeatingLeft(){ if(GetLeft() < heatLeft) digitalWrite(8,HIGH); else digitalWrite(8,LOW);}
float TERMAL::GetLeft() {sensors.requestTemperatures(); return sensors.getTempC(ds2);}


void TERMAL::SetRight(int r){heatRight = r;}
void TERMAL::HeatingRight(){ if(GetRight() < heatRight) digitalWrite(9,HIGH);else digitalWrite(9,LOW);}
float TERMAL::GetRight() {return (float)heatRight;}


void TERMAL::Cooling(char c){
  switch(c){
    case 'o': Serial.println("Cooling Off"); analogWrite(21,0); break;
    case 'l': Serial.println("Cooling Low"); analogWrite(21,85); break;
    case 'm': Serial.println("Cooling Medium"); analogWrite(21,170); break;
    case 'h': Serial.println("Cooling High"); analogWrite(21,255); break;}
}
