#ifndef TRACK_H
#define TRACK_H

#include <string>
#include "duration.h"

struct Track {
    std::string title;
    std::string artist;
    Duration length;

    Track() : title(""), artist(""), length(0, 0) {}
    Track(std::string t, std::string a, Duration len) 
        : title(t), artist(a), length(len) {}
};

#endif 
