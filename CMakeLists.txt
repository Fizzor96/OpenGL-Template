cmake_minimum_required(VERSION 3.20.0)
project(Application VERSION 0.1.0)
set(EXECUTABLE_OUTPUT_PATH "bin")
add_subdirectory(deps)
find_package(OpenGL REQUIRED)
set(BUILD_SHARED_LIBS OFF)

include_directories(
    deps/glfw-3.3.8/include
    deps/glew-2.2.0/include
    deps/glm/include
    .
)

if(WIN32)
    set(OpenGL_GL_PREFERENCE GLVND)
    list(APPEND ALL_LIBS OpenGL::GL)
    add_executable(${CMAKE_PROJECT_NAME} main.cpp)
else()
    set(OpenGL_GL_PREFERENCE LEGACY)
    list(APPEND ALL_LIBS OpenGL::OpenGL)
    add_executable(${CMAKE_PROJECT_NAME} main.cpp)
    target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC -g -Wall -Wunused -Wno-dev)
endif()

target_link_libraries(${CMAKE_PROJECT_NAME} glfw glew_s glm::glm)