
#include "gtest/gtest.h"

TEST(HelloTests, TestTrue) {
    int n = 2;
    ASSERT_TRUE(n == 2);
}

TEST(HelloTests, TestFalse) {
    int n = 2;
    ASSERT_FALSE(n == 5);
}

TEST(HelloTests, TestEq) {
    int n = 2;
    ASSERT_EQ(n, 2);
}

TEST(HelloTests, TestNe) {
    int n = 2;
    ASSERT_NE(3, n);
}