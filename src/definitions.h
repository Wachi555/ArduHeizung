#pragma once

#define PIN_SENSOR 13
#define PIN_MAIN 11
#define PIN_SECOND 12

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

struct Time {
    unsigned int hour;
    unsigned int minute;  
    Time(unsigned int h, unsigned int m) : hour(h), minute(m) {};
};
