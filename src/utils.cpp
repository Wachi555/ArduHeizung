#include "utils.h"
#include <RTClib.h>
#include "definitions.h"
#include "sensors.h"

RTC_DS1307 rtcBoard;

extern Settings settings;

void setup_rtc() {
    rtcBoard.begin();
    // rtcBoard.adjust(DateTime(2023, 7, 28, 16, 489, 0)); // to get the correct time
}

Time get_time() {
    return Time(rtcBoard.now().hour(), rtcBoard.now().minute());
}

bool isDay() {
    Time time = get_time();
    return time.hour >= settings.day.begin && time.hour < settings.day.end;
}

void setup_pins() {
    pinMode(PIN_MAIN, OUTPUT);
    pinMode(PIN_SECOND, OUTPUT);
    pinMode(PIN_UP, INPUT_PULLUP);
    pinMode(PIN_DOWN, INPUT_PULLUP);
    pinMode(PIN_ENTER, INPUT_PULLUP);
}

void loop_input() {
    static int inc_test = 0;
    if (digitalRead(PIN_UP) == LOW) {
        if (digitalRead(PIN_DOWN) == LOW) {
            // +
            inc_test++;
        } else {
            // -
            inc_test--;
        }
        Serial.print(inc_test);
        delay(50); // debounce
    }
    if (digitalRead(PIN_ENTER) == LOW) {
        Serial.print("Enter");
        
        while (digitalRead(PIN_ENTER) == LOW); // blocks until button isn't pressed -> one execution
        delay(50); // debounce
    }
}

void serial_output() {
    Serial.print(Temp().main);
    Serial.print("   ");
    Serial.println(Temp().second);
}