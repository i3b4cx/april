
###########################################
# CMAKELISTS : WINNEBAGO PROJECT          #
###########################################

# SET PROJECT VARIABLES
cmake_minimum_required(VERSION 3.26.0)
project(winnebago VERSION 0.1)
set(CMAKE_CXX_STANDARD_REQUIRED 11)
set(CMAKE_CXX_FLAGS "-O2 -g -Wall -Werror")

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)

# SET PROJECT SRC/INC FILES
set(src
    src/core/Window.cpp
    src/core/Context.cpp)
set(test_src
    )

# DEFINE PROJECT OPTIONS
option(TESTS "Build Tests" OFF)

# DEFINE PROJECT LIBRARIES (OPTIONAL)


# DEFINE EXECUTABLES
add_executable(winnebago.o main/main.cpp ${src})
if(TESTS)
    enable_testing()
    add_executable(tests ext/googletest/googletest/src/gtest_main.cc ${test_src})
endif()

# DEFINE INCLUDE DIRECTORIES
target_include_directories(winnebago.o
    PRIVATE
    {$CMAKE_SOURCE_DIR}/include/winnebago
    )
if(TESTS)
    target_include_directories(tests
        PRIVATE
        ${test_inc})
endif()

# DEFINE SUBDIRECTORIES
if(TESTS)
    add_subdirectory(ext/googletest googletest)
endif()

# LINK LIBRARIES
if(TESTS)
    target_link_libraries(tests gtest)
endif(TESTS)
target_link_libraries(winnebago.o ${SDL2_LIBRARIES} ${GL_LIBRARIES})

# INSTALL LIBRARIES (OPTIONAL)


# INSTALL BINARIES (OPTIONAL)


# BUILD MESSAGES (OPTIONAL)
# message("")
