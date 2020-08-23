cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

project(app_project LANGUAGES CXX)
set(SOURCE_EXE main.cpp)
add_subdirectory(src)
include_directories(../3dparty/SFML/include/SFML/)

add_compile_options(
        -std=c++17
        -Werror
        -Wall
        -Wextra
        -Wpedantic
        -Wno-unused-parameter
)

add_executable(MyProject main.cpp)
target_link_libraries (MyProject sfml-graphics sfml-window sfml-system)
add_executable(race00 ${SOURCE_EXE})
target_link_libraries(race00 src)
