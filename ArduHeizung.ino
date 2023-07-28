#include <LiquidCrystal_I2C.h>
#include <avr/wdt.h>
#include "src/sensors.h"
#include "src/definitions.h"
#include "src/output.h"
#include "src/utils.h"

Settings settings;

void setup() {
    Serial.begin(9600);
    setup_sensors();
    setup_pins();
    Serial.println("Setup complete");
}

void loop() {
    Serial.print(Temp().main);
    Serial.print("   ");
    Serial.println(Temp().second);

    control_output();
    delay(3000);
}