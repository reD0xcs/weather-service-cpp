#include <gtest/gtest.h>

TEST(Dummy, will_fail)
{
    EXPECT_EQ(1, 2);
}

// provides main() for the test executable
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}