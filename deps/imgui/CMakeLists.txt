target_sources(${CMAKE_PROJECT_NAME}
    PUBLIC imgui.cpp
    PUBLIC imgui_draw.cpp
    PUBLIC imgui_tables.cpp
    PUBLIC imgui_widgets.cpp
    PUBLIC imgui_demo.cpp
)

add_subdirectory(backends)