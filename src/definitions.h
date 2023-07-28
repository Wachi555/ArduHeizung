#pragma once

#define PIN_SENSOR 13

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
