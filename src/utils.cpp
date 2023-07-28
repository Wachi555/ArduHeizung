#include "utils.h"
#include <RTClib.h>
#include "definitions.h"

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
    if (time.hour >= settings.day.begin && time.hour < settings.day.end)
        return true;
    return false;
}

void setup_pins() {
    pinMode(PIN_MAIN, OUTPUT);
    pinMode(PIN_SECOND, OUTPUT);
}