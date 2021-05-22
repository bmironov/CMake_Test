# CMakeList.txt : CMake project for CMake_VS_Testing2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.15)


project ("CMake_Test" VERSION 9.8.7.6)

# We have to add CTest in root CMakeLists.txt in order to discover all tests
# in all subdirectories of the whole project
include(CTest)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)


add_subdirectory(object)
add_subdirectory(apps)

add_subdirectory(tests)
