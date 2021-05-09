
#include "object.h"


int Object::get_number() const {
    return number;
}


std::string Object::get_name() const {
    return name;
}


void Object::set_number(int n) {
    number = n;
}


void Object::set_name(std::string str) {
    name = str;
}


std::string Object::get_version() const {
    return version;
}