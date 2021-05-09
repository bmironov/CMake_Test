# CMakeList.txt : CMake project for CMake_VS_Testing2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("CMake_VS_Testing2")

# Add source to this project's executable.
add_executable (CMake_VS_Testing2 "CMake_VS_Testing2.cpp" "CMake_VS_Testing2.h")

# TODO: Add tests and install targets if needed.

add_subdirectory(tests)
