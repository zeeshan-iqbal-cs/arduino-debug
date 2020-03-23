/*
  Debug.cpp - Library for begugging arduino code easily
  Created by Zeeshan Iqbal, Feb 25, 2020.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Debug.h"


void Debug::begin(bool debugFlag, int n, String className){
  this->debugFlag = debugFlag;
  this->nTab = n;
  this->className = className + ".";

  this->funcName = "";
  this->newPrint = true;
}


void Debug::beginFunc(String funcName){
  this->funcName = funcName;
  nTab += 2;
  this->println(String("----- START-") + className + funcName);
}


void Debug::endFunc(){
  this->println(String("----- End-") + className + funcName + "\n");
  this->funcName = "";
  nTab -= 2;
}


void Debug::print(String line){
  if (this->debugFlag){
    this->printBase();
    Serial.print(line);
  }
}


void Debug::println(String line){
  if (this->debugFlag){
    this->printBase();
    Serial.println(line);
    this->newPrint = true;
  }
  delay(25);
}


void Debug::printBase(){
  if (this->newPrint){
    for (int i=0; i < nTab; i++){
      Serial.print("=");
    }
    Serial.print("] ");
    this->newPrint = false;
  }
  delay(25);
}
