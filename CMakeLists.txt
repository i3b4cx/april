
###########################################
# CMAKELISTS : STARTER PROJECT            #
###########################################

# SET PROJECT VARIABLES
cmake_minimum_required(VERSION 3.26.0)
project(starter VERSION 0.1)
set(CMAKE_CXX_STANDARD_REQUIRED 11)
set(CMAKE_CXX_FLAGS "-O2 -g -Wall -Werror")

# SET PROJECT SRC/INC FILES
set(src
    ...)
set(test_src
    ...)
set(inc
    ...)
set(test_inc
    ...)

# DEFINE PROJECT OPTIONS
option(TESTS "Build Tests" OFF)

# DEFINE PROJECT LIBRARIES (OPTIONAL)


# DEFINE EXECUTABLES
add_executable(starter.o main/main.cpp ${src})
if(TESTS)
    enable_testing()
    add_executable(tests ext/googletest/googletest/src/gtest_main.cc ${test_src})
endif()

# DEFINE INCLUDE DIRECTORIES
target_include_directories(starter.o
    PRIVATE
    ${inc})
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

# INSTALL LIBRARIES (OPTIONAL)


# INSTALL BINARIES (OPTIONAL)


# BUILD MESSAGES (OPTIONAL)
# message("")
