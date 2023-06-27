target_sources(${CMAKE_PROJECT_NAME}
    PUBLIC imgui.cpp
    PUBLIC imgui_draw.cpp
    PUBLIC imgui_tables.cpp
    PUBLIC imgui_widgets.cpp
)

add_subdirectory(backends)