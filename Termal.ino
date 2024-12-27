#include "Termal.h"

TERMAL::TERMAL(){pinMode(3,OUTPUT);pinMode(2,OUTPUT);pinMode(1,OUTPUT);pinMode(6,OUTPUT);pinMode(5, OUTPUT);
                 heatFront = 0, heatBack = 0, heatLeft = 0, heatRight = 0;}


void TERMAL::SetFront(int f){heatFront = f;}
void TERMAL::HeatingFront(){ if(GetFront() < heatFront) digitalWrite(6,HIGH);  else digitalWrite(6,LOW);}
float TERMAL::GetFront() {sensors.requestTemperatures(); return 22   /*sensors.getTempC(ds0)*/;}


void TERMAL::SetBack(int b){heatBack = b;}
void TERMAL::HeatingBack(){ if(GetBack() < heatBack) digitalWrite(2,HIGH); else digitalWrite(2,LOW);}
float TERMAL::GetBack() {sensors.requestTemperatures(); return sensors.getTempC(ds1);}


void TERMAL::SetLeft(int l){heatLeft = l;}
void TERMAL::HeatingLeft(){ if(GetLeft() < heatLeft) digitalWrite(1,HIGH); else digitalWrite(1,LOW);}
float TERMAL::GetLeft() {sensors.requestTemperatures(); return sensors.getTempC(ds2);}


void TERMAL::SetRight(int r){heatRight = r;}
void TERMAL::HeatingRight(){ if(GetRight() < heatRight) digitalWrite(3,HIGH);else digitalWrite(3,LOW);}
float TERMAL::GetRight() {return (float)heatRight;}


void TERMAL::Cooling(char c){
  switch(c){
    case 'o': Serial.println("Cooling Off"); analogWrite(5,0); break;
    case 'l': Serial.println("Cooling Low"); analogWrite(5,85); break;
    case 'm': Serial.println("Cooling Medium"); analogWrite(5,170); break;
    case 'h': Serial.println("Cooling High"); analogWrite(5,255); break;}
}
