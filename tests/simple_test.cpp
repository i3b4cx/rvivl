#include <gtest/gtest.h>

// Simple function to test
int Add(int a, int b) { return a + b; }

// Test case
TEST(SimpleTest, Addition) {
    EXPECT_EQ(Add(2, 3), 5);
    EXPECT_EQ(Add(-1, 1), 0);
    EXPECT_NE(Add(2, 2), 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
