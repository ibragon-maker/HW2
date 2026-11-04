#include <iostream>
#include "duration.h"
#include "track.h"
#include "playlist.h"

int main() {
    Playlist myPlaylist(3);

    Track t1("Song A", "Artist A", Duration(3, 45));
    Track t2("Song B", "Artist B", Duration(2, 30));
    Track t3("Song C", "Artist C", Duration(4, 15));

    myPlaylist.add_track(t1);
    myPlaylist.add_track(t2);
    myPlaylist.add_track(t3);

    std::cout << "Playlist Capacity: " << myPlaylist.capacity() << std::endl;
    std::cout << "Playlist Size: " << myPlaylist.size() << std::endl;
    std::cout << "Total Length: " << myPlaylist.total_length() << std::endl;

    Track* found = myPlaylist.find_track("Song B");
    if (found != nullptr) {
        std::cout << "Found track: " << found->title << " by " << found->artist << " (" << found->length << ")" << std::endl;
    } else {
        std::cout << "Track not found." << std::endl;
    }

    return 0;
}
