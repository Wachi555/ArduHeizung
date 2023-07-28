#include "sensors.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include "definitions.h"

OneWire oneWire(PIN_SENSOR);
DallasTemperature sensors(&oneWire);
DeviceAddress sens_main, sens_second;

Temp::Temp() {
    sensors.requestTemperatures();
    main = sensors.getTempC(sens_main);
    second = sensors.getTempC(sens_second);
}

void setup_sensors() {
    sensors.begin();
    sensors.getAddress(sens_main, 0);
    sensors.getAddress(sens_second, 1);
}