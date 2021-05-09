# CMakeList.txt : CMake project for CMake_VS_Testing2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.15)

project ("CMake_VS_Testing" VERSION 0.1.0)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)


# Add source to this project's executable.
add_subdirectory(hello)
add_subdirectory(apps)

# TODO: Add tests and install targets if needed.
add_subdirectory(tests)
