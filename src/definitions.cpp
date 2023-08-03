#pragma once

#include "definitions.h"
#include <Arduino.h>

Timer::Timer(float duration_sec, bool restart = false) {
    start = millis();
    duration_sec *= 1000;
    duration = long(duration_sec);
    end = start + duration;

    auto_restart = restart;
}

bool Timer::operator()() {
    if (millis() < end) return true; // timer still running

    if (auto_restart) restart(); // restarts timer if auto restart is enabled
    return false;
}

void Timer::restart() {
    start = millis();
    end = start + duration;
}