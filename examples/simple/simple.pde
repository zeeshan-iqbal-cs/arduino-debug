#include <Debug.h>

Debug debug;

void setup(){
    Serial.begin(9600); while(! Serial);
    
    debug.begin(true, 2, "MAIN");
    debug.beginFunc("setup");
    debug.println("Hello setup");
    debug.endFunc();
}

int i = 0;


void loop(){
    i++;
    debug.beginFunc("LOOP");
    
    debug.println(String("Hello LOOP[") + i + "]");
    
    debug.endFunc();
}
