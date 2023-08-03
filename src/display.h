#pragma once

#include <LiquidCrystal_I2C.h>

class Display {

    LiquidCrystal_I2C lcd;
    int line = 0;
    int pos = 0;
    
    public:
    String content[4];

    Display();

    void setup();

    void println(String s);

    void print(String s);
    
    void print_menu(String s[]);

    void reset();
    
};

void loop_display(Display &d);