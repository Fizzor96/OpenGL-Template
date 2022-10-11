cmake_minimum_required(VERSION 3.20.0)
project(Application VERSION 0.1.0)
set(EXECUTABLE_OUTPUT_PATH "bin")

add_subdirectory(deps)

set(OpenGL_GL_PREFERENCE GLVND CACHE STRING "" FORCE)
find_package(OpenGL REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

include_directories(
    deps/glfw-3.3.8/include
    deps/glew-2.2.0/include
    deps/glm/include
    .
)

set(ALL_LIBS
    glfw
    glew_s
    glm::glm
)

if(NOT UNIX)
    list(APPEND ALL_LIBS OpenGL::GL)
else()
    list(APPEND ALL_LIBS OpenGL::OpenGL)
endif()

add_definitions(
    -DGLEW_STATIC
)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)
target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC -g -Wall -Wunused -Wno-dev)
target_link_libraries(${CMAKE_PROJECT_NAME} ${ALL_LIBS})