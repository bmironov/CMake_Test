
#include <atomic>
#include <chrono>
#include <random>
#include <thread>
#include <iostream>
#include <vector>
#include "main_config.h"
#include "object.h"


std::atomic_flag lock = ATOMIC_FLAG_INIT;

// Initialize random number generator
std::mt19937_64 engine{ std::random_device{}() };
std::uniform_int_distribution<> distribution{ 10, 1000 };


void doSomething(int id) {

    // emulate useful activity in the thread
    std::this_thread::sleep_for(std::chrono::milliseconds{ distribution(engine) });

    // acquire lock
    while (lock.test_and_set(std::memory_order_acquire)) {}

    std::cout << "# " << id << std::endl;

    // release lock
    lock.clear(std::memory_order_release);
}


void spawnThreads() {
    std::vector<std::thread> threads;

    std::cout << "Spawning " << std::thread::hardware_concurrency() << " threads:" << std::endl;

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
