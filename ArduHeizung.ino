#include <avr/wdt.h>
#include "src/sensors.h"
#include "src/definitions.h"
#include "src/output.h"
#include "src/utils.h"
#include "src/display.h"

Settings settings;
Display display;
State state;


void setup() {
    Serial.begin(9600);
    setup_sensors();
    setup_pins();
    display.setup();

    Serial.println("Setup complete");
}

void loop() {
    static Timer display_t(3, true);
    if(!display_t()) {
        serial_output();
        control_output();
        loop_display(display);
    }
    loop_input();
    
}