cmake_minimum_required(VERSION 3.10)
project(StTriangulator LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Add GLFW subdirectory
add_subdirectory(lib/glfw)

# Set ImGui directory
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/lib/imgui)

# List ImGui source files
set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

# Add ImGui as a static library
add_library(imgui STATIC ${IMGUI_SOURCES})

# Include directories for ImGui
target_include_directories(imgui PUBLIC
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
)

# Link ImGui dependencies
target_link_libraries(imgui PUBLIC
    glfw
    OpenGL::GL
)

# Create the executable
add_executable(StTriangulator
    src/main.cpp
    src/App.cpp

    Theme/colors.cpp
    Theme/style.cpp
    
    src/GUI/GUI.cpp
    src/GUI/TitleBar.cpp
    src/GUI/renderBody.cpp

    src/core/Solver.cpp
)

# Link the executable with ImGui and dependencies
target_link_libraries(StTriangulator PRIVATE imgui)