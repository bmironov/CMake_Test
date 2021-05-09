# version 3.15 or later of CMake needed for GoogleTest on Windows
cmake_minimum_required(VERSION 3.15)

include(CTest)

enable_testing()

project(main VERSION 0.1.2)

add_executable(${PROJECT_NAME} main.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

# We need object.h and the object library
target_link_libraries(${PROJECT_NAME}
    PRIVATE object)

configure_file(main_config.h.in main_config.h)
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}")

# Adding support for multi-threading
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

target_link_libraries(${PROJECT_NAME} PUBLIC
								${CMAKE_THREAD_LIBS_INIT})

# does the application run
add_test(NAME It_Runs_Without_Segfault COMMAND ${PROJECT_NAME})

