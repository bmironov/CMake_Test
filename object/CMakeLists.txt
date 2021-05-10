# version 3.15 or later of CMake needed for GoogleTest on Windows
# so let's require it now.
cmake_minimum_required(VERSION 3.15)

project(object)

set(BUILD_SHARED_LIBS ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS True)

add_library(${PROJECT_NAME} src/object.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_include_directories(${PROJECT_NAME} PUBLIC "${MAIN_BINARY_DIR}")

# PUBLIC needed to make both object.h and object library available elsewhere in project
target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include)


# Copy library to apps build directory
file(COPY "${PROJECT_BINARY_DIR}/${LIBRARY_OUTPUT_NAME}" DESTINATION "${PROJECT_BINARY_DIR}/../apps/")

# Copy library to tests build directory
file(COPY "${PROJECT_BINARY_DIR}/${LIBRARY_OUTPUT_NAME}" DESTINATION "${PROJECT_BINARY_DIR}/../tests/")
