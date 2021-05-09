# version 3.15 or later of CMake needed for GoogleTest on Windows
cmake_minimum_required(VERSION 3.15)

include(CTest)

enable_testing()

project(main VERSION 0.1.2)

add_executable(${PROJECT_NAME} main.cpp)

# We need hello.h and the hello library
target_link_libraries(${PROJECT_NAME}
    PRIVATE hello)

configure_file(main_config.h.in main_config.h)
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}")

# Tell C++ compiler to use C++20 features. We don't actually use any of them.
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

# does the application run
add_test(NAME It_Runs_Without_Segfault COMMAND ${PROJECT_NAME})
