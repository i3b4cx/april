
###########################################
# CMAKELISTS : APRIL PROJECT              #
###########################################

# SET PROJECT VARIABLES
cmake_minimum_required(VERSION 3.26.0)
project(april VERSION 0.1)
set(CMAKE_CXX_STANDARD_REQUIRED 11)
set(CMAKE_CXX_FLAGS "-O2 -g -Wall -Werror")

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(OpenGL REQUIRED gl)

# SET PROJECT SRC/INC FILES
set(APRIL_SRC
    src/core/Application.cpp
    src/core/Window.cpp
    src/core/Context.cpp)
set(test_src
    )
set(APRIL_INC
    ${CMAKE_SOURCE_DIR}/include/april)
# DEFINE PROJECT OPTIONS
option(TESTS "Build Tests" OFF)


# DEFINE LIBRARIES
add_library(april ${APRIL_SRC})
if(TESTS)
    enable_testing()
    add_executable(tests ext/googletest/googletest/src/gtest_main.cc ${test_src})
endif()

# DEFINE INCLUDE DIRECTORIES
target_include_directories(april
    PRIVATE
    ${APRIL_INC}
    ${SDL2_INCLUDE_DIRS}
    )
if(TESTS)
    target_include_directories(tests
        PRIVATE
        ${test_inc}
        ${SDL2_INCLUDE_DIRS})
endif()

# DEFINE SUBDIRECTORIES
if(TESTS)
    add_subdirectory(ext/googletest googletest)
endif()

# LINK LIBRARIES
if(TESTS)
    target_link_libraries(tests gtest)
endif(TESTS)
target_link_libraries(april ${SDL2_LIBRARIES} ${GL_LIBRARIES})

# DEFINE EXECUTABLES
add_executable(window
    samples/window/main.cpp)
target_include_directories(window PRIVATE ${APRIL_INC} PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(window april ${SDL2_LIBRARIES} )

# INSTALL LIBRARIES (OPTIONAL)


# INSTALL BINARIES (OPTIONAL)


# BUILD MESSAGES (OPTIONAL)
# message("")
