/*
  Debug.h - Libray for debugging arduino code easily
  Created by Zeeshan Iqbal, Feb 25, 2020
  Released into the public domain.
*/

#ifndef Debug_h
#define Debug_h

#include <Arduino.h>

class Debug{
  private:
  int nTab;
  bool debugFlag;
  bool newPrint;
  String className;
  String funcName;

  void printBase();

  public:
  void begin(bool debugFlag, int n=2, String className="");
  void beginFunc(String funcName);
  void endFunc();
  void print(String);
  void println(String);
  
};

#endif
