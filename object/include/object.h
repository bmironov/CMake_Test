
#pragma once

#ifndef OBJECT_INCLUDE_GUARD
#define OBJECT_INCLUDE_GUARD

#include <string>

class Object {
    public:
        int get_number() const;
        std::string get_name() const;
        std::string get_version() const;

        void set_number(int n);
        void set_name(std::string str);

        Object() { number = 0; name = ""; version = "123"; }

    protected:
        int number;
        std::string name;
        std::string version;
};


#endif // OBJECT_INCLUDE_GUARD
