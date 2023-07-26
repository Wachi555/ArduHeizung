#include <RTClib.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <avr/wdt.h>

#define PIN_SENSOR 13


// Sensors
OneWire oneWire(PIN_SENSOR);
DallasTemperature sensors(&oneWire);
DeviceAddress sens_main; // sens_second;


struct Temp { // used as temporary object to get current temperatures
    float main;
    Temp() {
        sensors.requestTemperatures();
        main = sensors.getTempC(sens_main);
    }  
};


void setup_sensors() {
    sensors.begin();
    sensors.getAddress(sens_main, 0);
}


void setup() {
    Serial.begin(9600);
    setup_sensors();

    Serial.println("Setup complete");
}

void loop() {
    Serial.println(Temp().main);
    delay(3000);
}
