#ifndef DURATION_H
#define DURATION_H

#include <iostream>

class Duration {
private:
    int m_total_seconds;

public:
    Duration(int minutes = 0, int seconds = 0);

    int total_seconds() const;

    Duration operator+(const Duration& other) const;
    bool operator==(const Duration& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Duration& d);
};

#endif // DURATION_H
