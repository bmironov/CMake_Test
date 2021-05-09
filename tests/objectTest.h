
#pragma once

#ifndef OBJECT_TEST_INCLUDE_GUARD
#define OBJECT_TEST_INCLUDE_GUARD


#include <string>
#include "object.h"


class ObjectTest : public Object {
    public:
        std::string get_status() const;

        ObjectTest() : Object() {};
};


#endif // OBJECT_TEST_INCLUDE_GUARD
