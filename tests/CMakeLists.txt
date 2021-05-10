
cmake_minimum_required(VERSION 3.15)

include(GoogleTest)
include(FetchContent)

enable_testing()


FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.10.0
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    if(MSVC)
        add_compile_options(/MD$<$<CONFIG:Debug>:d>)
    endif()   # MSVC
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()     # NOT googletest_POPULATED


mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

set_target_properties(gtest PROPERTIES FOLDER extern)
set_target_properties(gtest_main PROPERTIES FOLDER extern)
set_target_properties(gmock PROPERTIES FOLDER extern)
set_target_properties(gmock_main PROPERTIES FOLDER extern)


add_executable(UnitTest
    "main_Test.cpp"
    "objectTest.h" "objectTest.cpp" "object_Test.cpp"
)
target_compile_features(UnitTest PUBLIC cxx_std_17)

target_link_libraries(UnitTest gtest gmock gtest_main object)
gtest_discover_tests(UnitTest)
