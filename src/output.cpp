#include "output.h"
#include "utils.h"
#include "sensors.h"
#include "definitions.h"
#include "Arduino.h"

extern Settings settings;
extern State state;

void set_output(output o, bool value) {
    if (o == output::MAIN) {
        if (value) {
            digitalWrite(PIN_MAIN, LOW);
            state.output_main = true;
        }
        else {
            digitalWrite(PIN_MAIN, HIGH);
            state.output_main = false;
        }
    } else if (o == output::SECOND) {
        if (value) {
            digitalWrite(PIN_SECOND, LOW);
            state.output_second = true;
        }
        else {
            digitalWrite(PIN_SECOND, HIGH);
            state.output_second = false;
        }
    }
}

void control_output() {
    if (isDay()) {
        
        if (Temp().main < settings.temps.main_day) set_output(output::MAIN, true); // output main on
        else if (Temp().main > settings.temps.main_day + settings.temps.hystereisis)
            set_output(output::MAIN, false); // output main off
        
        if (Temp().second < settings.temps.second_day) set_output(output::SECOND, true); // output second on
        else if (Temp().second > settings.temps.second_day + settings.temps.hystereisis)
            set_output(output::SECOND, false); // output second off
    
    } else { // night
        
        if (Temp().main < settings.temps.main_night) set_output(output::MAIN, true); // output main on
        else if (Temp().main > settings.temps.main_night + settings.temps.hystereisis) 
            set_output(output::MAIN, false); // output main off
        
        if (Temp().second < settings.temps.second_night) set_output(output::SECOND, true); // output second on
        else if (Temp().second > settings.temps.second_night + settings.temps.hystereisis)
            set_output(output::SECOND, false); // output second off
    
    } 
}