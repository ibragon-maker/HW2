# Class Design & Invariants

## 1. Duration Class

### Private Data Members
* `int m_total_seconds`: Stores the overall duration converted into a single total number of seconds.

### Invariants
* `m_total_seconds >= 0`: The total seconds can never be negative. If someone tries to create a negative duration or ends up with negative total seconds, it gets clamped to 0.

### Public Functions
* `Duration(int minutes = 0, int seconds = 0)`: Constructor that takes minutes and seconds, rolls extra seconds into minutes, and clamps any negative result to 0 total seconds.
* `int total_seconds() const`: Returns the total length in seconds.
* `Duration operator+(const Duration& other) const`: Adds two durations together and returns a new Duration object without changing the originals.
* `bool operator==(const Duration& other) const`: Checks if two durations have the exact same total seconds.
* `std::ostream& operator<<(std::ostream& out, const Duration& d)`: Free function that prints the duration formatted as M:SS or MM:SS (with leading zero for seconds under 10).


## 2. Track Struct

* `Track` is just a simple record (struct) that combines a `std::string title` and a `Duration length`. It doesn't have its own invariants, but demonstrates composition since it contains a `Duration` object.


## 3. Playlist Class

### Private Data Members
* `Track* m_tracks`: Pointer to a dynamically allocated array of Track objects on the heap.
* `int m_count`: Tracks how many tracks are currently stored.
* `int m_capacity`: Stores the max capacity of the allocated array.

### Invariants
* `0 <= m_count <= m_capacity`: Count can't be negative and can never exceed capacity.
* `m_capacity >= 1`: Capacity has to be at least 1. Any constructor input under 1 gets clamped to 1.
* `m_tracks != nullptr`: `m_tracks` must always point to a valid dynamically allocated array of size `m_capacity`.
* No track stored in the playlist can have an empty title (`""`).

### Public Functions
* `explicit Playlist(int capacity)`: Allocates the array for `m_capacity` tracks (clamped to 1 minimum) and starts `m_count` at 0.
* `~Playlist()`: Destructor that frees the allocated track array using `delete[]` to avoid memory leaks.
* `Playlist(const Playlist&) = delete`: Prevents copying playlists so we don't accidentally get double-free errors.
* `Playlist& operator=(const Playlist&) = delete`: Prevents copy assignment for the same reason.
* `bool add_track(const Track& track)`: Copies a track into the array if there is room and the track title isn't empty. Returns `true` if added, `false` otherwise.
* `int size() const`: Returns the current number of tracks (`m_count`).
* `Duration total_length() const`: Calculates and returns the sum of all track durations using `operator+`.
* `const Track* find_track(const std::string& title) const`: Searches for a track by exact title match. Returns a pointer to it if found, or `nullptr` if it's missing.
