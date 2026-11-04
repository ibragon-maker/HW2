#include "playlist.h"
#include "duration.h"

Playlist::Playlist(int capacity) {
    if (capacity < 1) {
        m_capacity = 1;
    } else {
        m_capacity = capacity;
    }
    m_tracks = new Track[m_capacity];
    m_count = 0;
}

Playlist::~Playlist() {
    delete[] m_tracks;
    m_tracks = nullptr;
}

bool Playlist::add_track(const Track& track) {
    if (track.title.empty()) {
        return false;
    }
    if (m_count >= m_capacity) {
        return false;
    }
    m_tracks[m_count] = track;
    m_count++;
    return true;
}

int Playlist::size() const {
    return m_count;
}

int Playlist::capacity() const {
    return m_capacity;
}

Duration Playlist::total_length() const {
    Duration total(0, 0);
    for (int i = 0; i < m_count; ++i) {
        total = total + m_tracks[i].length;
    }
    return total;
}

Track* Playlist::find_track(const std::string& title) {
    for (int i = 0; i < m_count; ++i) {
        if (m_tracks[i].title == title) {
            return &m_tracks[i];
        }
    }
    return nullptr;
}
