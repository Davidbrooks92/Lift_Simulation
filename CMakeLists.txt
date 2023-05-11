cmake_minimum_required(VERSION 3.22)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

# download the Catch2 libary from git
Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.3.0 # or a later release
)
FetchContent_MakeAvailable(Catch2)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

# alternative with Catch2 in a subdirectory
#add_subdirectory(lib/Catch2)

# alternatively in CMake is installed system wide
#find_package(Catch2 3 REQUIRED)

add_executable(lifttest lift_simulation.cpp testing_lift.cpp)

# These tests can use the Catch2-provided main
target_link_libraries(lifttest PRIVATE Catch2::Catch2WithMain)

# Automatically discover tests
include(CTest)
include(Catch)
catch_discover_tests(lifttest)