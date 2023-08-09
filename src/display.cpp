#include "display.h"
#include "sensors.h"
#include "definitions.h"
#include <LiquidCrystal_I2C.h>

// #include <string.h>

Display::Display() : lcd(0x27, 20, 4) {}

void Display::setup() {
    lcd.init();
    lcd.backlight();
    lcd.clear();
    lcd.print("Yess?");
}

void Display::println(String s) {
    if (line == 4) line = 0;

    lcd.setCursor(pos, line++);
        
    if (s.length() < 20) lcd.print(s);
    else lcd.print("-- too long --");    

    pos = 0;
}

void Display::print(String s) {
    lcd.setCursor(pos, line);

    if (s.length() < 20) {
        lcd.print(s);
        pos += s.length();
    } else {
        lcd.print("-- too long --");
        pos = 0;
        line++;
    }
}

void Display::print_menu(String s[]) {
    line = 0;
    pos = 0;
    for(int i = 0; i < 4; i++) {
        println(s[i]);
    }
}

void Display::reset() {
    lcd.clear();
    pos = 0;
    line = 0;
}

void Display::switch_on() {
    on = true;
    lcd.backlight();
}

void Display::switch_off() {
    on = false;
    lcd.noBacklight();
}

void loop_display(Display &d, State &state) {
    d.reset();

    d.println("Main:");
    d.print(String(Temp().main, 1));
    if (state.output_main) d.println(" - on");
    else d.println(" - off");

    d.println("Second:");
    d.print(String(Temp().second, 1));
    if (state.output_second) d.println(" - on");
    else d.println(" - off");
}