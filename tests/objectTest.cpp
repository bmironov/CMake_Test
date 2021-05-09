
#include <string>
#include "objectTest.h"

std::string ObjectTest::get_status() const {
    return std::to_string(number) + ":" + name + ":" + version;
}
