
#include <iostream>
#include "main_config.h"
#include "hello.h"

int main(int, char**) {
    std::string helloJim = generateHelloString("Jim");
    std::cout << helloJim << std::endl;

    std::cout << "Project name: " << PROJECT_NAME
        << "  version: " << PROJECT_VERSION << std::endl;
    std::cout << "Major version: " << PROJECT_VERSION_MAJOR
        << "  Minor version: " << PROJECT_VERSION_MINOR
        << "  Patch version: " << PTOJECT_VERSION_PATCH << std::endl;

    return 0;
}
