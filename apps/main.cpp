
#include <thread>
#include <iostream>
#include <vector>
#include "main_config.h"
#include "object.h"


void doSomething(int id) {
    std::cout << id << std::endl;
}


void spawnThreads() {
    std::vector<std::thread> threads;

    // spawn n threads:
    for (unsigned int i = 0; i < std::thread::hardware_concurrency(); i++) {
        threads.push_back(std::thread(doSomething, i + 1));
    }

    for (auto& thread : threads) {
        thread.join();
    }
}


int main(int, char**) {
    Object n;

    // Check propagation of information from CMake to the app
    std::cout << "Project name: " << PROJECT_NAME
        << "  version: " << PROJECT_VERSION << std::endl;
    std::cout << "Major version: " << PROJECT_VERSION_MAJOR
        << "  Minor version: " << PROJECT_VERSION_MINOR
        << "  Patch version: " << PROJECT_VERSION_PATCH
        << "  Tweak version: " << PROJECT_VERSION_TWEAK << std::endl;

    spawnThreads();

    n.set_name("ABC XYZ");
    n.set_number(55);
    std::cout << "Object name: " << n.get_name()
        << "  number: " << n.get_number()
        << "  version: " << n.get_version() << std::endl;

    return 0;
}
