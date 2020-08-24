cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

project(app_project LANGUAGES CXX)
set(SOURCE_EXE main.cpp)
add_subdirectory(src)
add_subdirectory(render)
include_directories(../3dparty/SFML/include/SFML/)

add_compile_options(
        -std=c++17
        -Werror
        -Wall
        -Wextra
        -Wpedantic
        -Wno-unused-parameter
)

add_executable(race00 main.cpp src/Snake.cpp src/engine.cpp src/Menu.cpp
                src/LeaderBoard.cpp src/GameWindow.cpp src/GameOverWindow.cpp
                render/menuWindow.cpp render/GameWindow.cpp render/OptionWindow.cpp
                render/GameOverWindowRender.cpp)
target_link_libraries (race00 sfml-graphics sfml-window sfml-system)
