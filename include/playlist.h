#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "track.h"

class Playlist {
private:
    Track* m_tracks;
    int m_capacity;
    int m_count;

public:
    Playlist(int capacity = 10);
    ~Playlist();

    bool add_track(const Track& track);
    int size() const;
    int capacity() const;
    Duration total_length() const;
    Track* find_track(const std::string& title);
};

#endif
