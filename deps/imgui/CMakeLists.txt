file(GLOB imgui_src
    "*.cpp"
)

target_sources(${CMAKE_PROJECT_NAME}
    PUBLIC ${imgui_src}
)