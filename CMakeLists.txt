cmake_minimum_required(VERSION 3.20.0)
project(Application VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
set(OpenGL_GL_PREFERENCE GLVND)
set(BUILD_SHARED_LIBS OFF)

if(WIN32)
    list(APPEND ALL_LIBS OpenGL::GL)
else()
    list(APPEND ALL_LIBS OpenGL::OpenGL)
endif(WIN32)

set(DEPENDENCY_INCLUDES
    ${PROJECT_SOURCE_DIR}/deps/glfw-3.3.8/include
    ${PROJECT_SOURCE_DIR}/deps/glew-2.2.0/include
    ${PROJECT_SOURCE_DIR}/deps/glm/include
    ${PROJECT_SOURCE_DIR}/deps/spdlog/include
    ${PROJECT_SOURCE_DIR}/deps/freetype/include
    ${PROJECT_SOURCE_DIR}/deps/imgui
)

set(GLFW_DIR "${PROJECT_SOURCE_DIR}/deps/glfw-3.3.8/glfw")
set(APPLICATION_INCLUDES
    ${PROJECT_SOURCE_DIR}/src
)

set(DEPENDENCY_LIBS
    glfw
    glew_s
    glm::glm
    freetype
)

if(MSVC)
    set(DEBUG_CONSOLE TRUE CACHE BOOL "Set the subsys to windows (means no console)")

    if(DEBUG_CONSOLE)
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:CONSOLE")
    else()
        add_compile_definitions(NODEBUG)
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
    endif(DEBUG_CONSOLE)

    add_compile_options(/W4 /wd4100 /wd4244 /wd4706 /wd4005 /wd4267 /wd4189 /wd4458)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Wpragmas -Wunused-parameter)
endif(MSVC)

add_executable(${CMAKE_PROJECT_NAME} WIN32 src/main.cpp)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${DEPENDENCY_INCLUDES} PUBLIC ${APPLICATION_INCLUDES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${DEPENDENCY_LIBS})

add_subdirectory(deps)
add_subdirectory(src)