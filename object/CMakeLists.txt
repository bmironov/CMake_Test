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


add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD 
  COMMAND "${CMAKE_COMMAND}" -E copy 
     "$<TARGET_FILE:object>"
     "../apps/$<TARGET_FILE_NAME:object>" 
  COMMENT "Copying to output directory")

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD 
  COMMAND "${CMAKE_COMMAND}" -E copy 
     "$<TARGET_FILE:object>"
     "../tests/$<TARGET_FILE_NAME:object>" 
  COMMENT "Copying to tests directory")
