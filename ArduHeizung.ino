#include <RTClib.h>
#include <LiquidCrystal_I2C.h>
#include <avr/wdt.h>
#include "src/sensors.h"
#include "src/definitions.h"

Settings settings;

void setup() {
    Serial.begin(9600);
    setup_sensors();
    Serial.println("Setup complete");
}

void loop() {
    

    delay(3000);
}

void control_output() {
    if (true) { // day
        if (Temp().main < settings.temps.main_day); // output main on
        else; // output second off
        if (Temp().second < settings.temps.second_day); // output second on
        else; // output second off
    } else {
        if (Temp().main < settings.temps.main_night); // output main on
        else; // output main off
        if (Temp().second < settings.temps.second_night); // output second on
        else; // output second off
    } 
}