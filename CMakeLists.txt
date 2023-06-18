
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
    src/components/Animate.cpp
    src/components/Audio.cpp
    src/components/Input.cpp
    src/components/Message.cpp
    src/components/Render.cpp
    
    src/core/Application.cpp
    src/core/Context.cpp
    src/core/ID.cpp
    src/core/Layer.cpp
    src/core/Object.cpp
    src/core/ObjectPool.cpp
    src/core/Registry.cpp
    src/core/Renderer.cpp
    src/core/Scene.cpp
    src/core/Window.cpp

    src/ecs/Component.cpp
    src/ecs/Entity.cpp
    src/ecs/Enums.cpp
    src/ecs/System.cpp

    src/graphics/api/gl2.cpp
    src/graphics/RenderImpl.cpp
    src/graphics/RenderStrategy.cpp
    src/graphics/RenderTarget.cpp
    src/graphics/RendererFactory.cpp
    
    src/network/Client.cpp
    src/network/Protocol.cpp
    src/network/Server.cpp
    src/network/Socket.cpp

    src/scenegraph/description/Camera.cpp
    src/scenegraph/description/DirectionalLight.cpp
    src/scenegraph/description/FlashLight.cpp
    src/scenegraph/description/Material.cpp
    src/scenegraph/description/Model.cpp
    src/scenegraph/description/PointLight.cpp
    src/scenegraph/description/Quad.cpp
    src/scenegraph/description/SpotLight.cpp
    src/scenegraph/description/Text.cpp
    src/scenegraph/description/Texture.cpp
    src/scenegraph/Camera.cpp
    src/scenegraph/DirectionalLight.cpp
    src/scenegraph/FlashLight.cpp
    src/scenegraph/Material.cpp
    src/scenegraph/Model.cpp
    src/scenegraph/PointLight.cpp
    src/scenegraph/Quad.cpp
    src/scenegraph/SpotLight.cpp
    src/scenegraph/Text.cpp
    src/scenegraph/Texture.cpp

    src/shaders/Basic.cpp
    src/shaders/BlinnPhong.cpp
    src/shaders/Phong.cpp
    src/shaders/UI.cpp

    src/systems/AnimationSystem.cpp
    src/systems/AudioSystem.cpp
    src/systems/InputSystem.cpp
    src/systems/MessageSystem.cpp
    src/systems/RenderSystem.cpp

    src/util/ArgParser.cpp
    src/util/Exception.cpp
    src/util/Logger.cpp
    src/util/Profiler.cpp
    )
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

add_executable(layer-scene-system
    samples/layer-scene-system/main.cpp)
target_include_directories(layer-scene-system PRIVATE ${APRIL_INC} PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(layer-scene-system april ${SDL2_LIBRARIES} )

# INSTALL LIBRARIES (OPTIONAL)


# INSTALL BINARIES (OPTIONAL)


# BUILD MESSAGES (OPTIONAL)
# message("")
