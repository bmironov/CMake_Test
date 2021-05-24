# version 3.15 or later of CMake needed for GoogleTest on Windows
cmake_minimum_required(VERSION 3.15)

include(CTest)

enable_testing()

project(main)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} main.cpp)

list(APPEND EXTRA_LIBS object)

target_link_libraries(${PROJECT_NAME} PRIVATE ${EXTRA_LIBS})

configure_file(main_config.h.in main_config.h)
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}")

# Adding support for multi-threading
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

target_link_libraries(${PROJECT_NAME} PUBLIC
								${CMAKE_THREAD_LIBS_INIT})

# How to avoid EBF test naming and group all CTests into single group in Visual Studio Test Explorer
# https://developercommunity.visualstudio.com/t/cmake-weird-test-name-prefix/793209#T-N1227948

# does the application run
add_test(NAME "app.Parameters.CoreTests.It_Runs_Without_Segfault" COMMAND ${PROJECT_NAME})
add_test(NAME "app.Parameters.CoreTests.Check_Parameter"          COMMAND ${PROJECT_NAME} -?)
