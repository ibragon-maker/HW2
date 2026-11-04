#include <gtest/gtest.h>
#include "duration.h"
#include "track.h"
#include "playlist.h"

TEST(DurationTest, DefaultAndParameterizedConstructor) {
    Duration d1;
    EXPECT_EQ(d1.total_seconds(), 0);

    Duration d2(2, 30);
    EXPECT_EQ(d2.total_seconds(), 150);
}

TEST(DurationTest, OperatorAddition) {
    Duration d1(1, 30);
    Duration d2(2, 15);
    Duration sum = d1 + d2;
    EXPECT_EQ(sum.total_seconds(), 225); 
}

TEST(DurationTest, EqualityOperator) {
    Duration d1(3, 0);
    Duration d2(3, 0);
    Duration d3(2, 59);
    EXPECT_TRUE(d1 == d2);
    EXPECT_FALSE(d1 == d3);
}

TEST(PlaylistTest, InitializationAndCapacity) {
    Playlist p(5);
    EXPECT_EQ(p.size(), 0);
    EXPECT_EQ(p.capacity(), 5);
}

TEST(PlaylistTest, AddTrackAndSize) {
    Playlist p(2);
    Track t1("Song 1", "Artist 1", Duration(2, 0));
    Track t2("Song 2", "Artist 2", Duration(3, 30));

    EXPECT_TRUE(p.add_track(t1));
    EXPECT_EQ(p.size(), 1);

    EXPECT_TRUE(p.add_track(t2));
    EXPECT_EQ(p.size(), 2);

    Track t3("Song 3", "Artist 3", Duration(1, 0));
    EXPECT_FALSE(p.add_track(t3));
    EXPECT_EQ(p.size(), 2);
}

TEST(PlaylistTest, FindTrackAndTotalLength) {
    Playlist p(3);
    p.add_track(Track("Alpha", "A", Duration(1, 30)));
    p.add_track(Track("Beta", "B", Duration(2, 30)));

    EXPECT_EQ(p.total_length().total_seconds(), 240); 

    Track* found = p.find_track("Beta");
    ASSERT_NE(found, nullptr);
    EXPECT_EQ(found->title, "Beta");

    Track* notFound = p.find_track("Gamma");
    EXPECT_EQ(notFound, nullptr);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
