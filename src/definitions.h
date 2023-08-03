#pragma once

#define PIN_DOWN 5
#define PIN_UP 6
#define PIN_ENTER 7
#define PIN_MAIN 11
#define PIN_SECOND 12
#define PIN_SENSOR 13

enum class output {
    MAIN, SECOND
};

struct Settings {
    struct Temps {
        float main_day = 45;
        float main_night = 40;

        float second_day = 45;
        float second_night = 40;

        float hystereisis = 5;
    };

    struct Day {
        int begin = 5;
        int end = 13;
    };

    Temps temps;
    Day day;

};

struct State {
    bool output_main = false;
    bool output_second = false;
};

struct Time {
    unsigned int hour;
    unsigned int minute;  
    Time(unsigned int h, unsigned int m) : hour(h), minute(m) {};
};

struct Timer {
    unsigned long start;
    unsigned long end;
    unsigned long duration;
    bool auto_restart;

    Timer(float duration_sec, bool auto_restart = false);
    
    bool operator()();

    void restart();
};
