
#include <gtest/gtest.h>
#include <string>
#include "objectTest.h"


TEST(Object, GetSetNumber) {
    ObjectTest n;
    int i = 34;

    EXPECT_EQ(0, n.get_number());

    n.set_number(i);
    EXPECT_EQ(i, n.get_number());
}


TEST(Object, GetSetName) {
    ObjectTest n;
    std::string str = "ABC";

    EXPECT_STREQ("", n.get_name().c_str());

    n.set_name(str);
    EXPECT_STREQ(str.c_str(), n.get_name().c_str());
}



TEST(Object, GetVersion) {
    ObjectTest n;

    EXPECT_STREQ("123", n.get_version().c_str());
}



TEST(Object, GetStatus) {
    ObjectTest n;

    EXPECT_STREQ("0::123", n.get_status().c_str());

    n.set_number(321);
    n.set_name("ABC");
    EXPECT_STREQ("321:ABC:123", n.get_status().c_str());
}
