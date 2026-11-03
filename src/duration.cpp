#include "duration.h"
#include <iomanip>

Duration::Duration(int minutes, int seconds) {
    int raw_seconds = (minutes * 60) + seconds;
    if (raw_seconds < 0) {
        m_total_seconds = 0;
    } else {
        m_total_seconds = raw_seconds;
    }
}

int Duration::total_seconds() const {
    return m_total_seconds;
}

Duration Duration::operator+(const Duration& other) const {
    int sum = m_total_seconds + other.m_total_seconds;
    return Duration(0, sum); 
}

bool Duration::operator==(const Duration& other) const {
    return m_total_seconds == other.m_total_seconds;
}

std::ostream& operator<<(std::ostream& os, const Duration& d) {
    int total = d.total_seconds();
    int mins = total / 60;
    int secs = total % 60;
    
    os << mins << ":" << std::setw(2) << std::setfill('0') << secs;
    return os;
}
