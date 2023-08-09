#include <avr/wdt.h>
#include "src/sensors.h"
#include "src/definitions.h"
#include "src/output.h"
#include "src/utils.h"
#include "src/display.h"

Settings settings;
Display display;

void setup() {
    Serial.begin(9600);
    setup_sensors();
    setup_pins();
    display.setup();

    Serial.println("Setup complete");
}

void loop() {
    static Timer update_t(5, true);
    static Timer display_t(10);
    static State state;

    loop_input(display_t);

    if (!display_t()) {
        if (display.on) display.switch_off();
        return;
    }
    display.switch_on();

    if (!update_t()) {
        serial_output();
        control_output();
        loop_display(display, state);
    }
}