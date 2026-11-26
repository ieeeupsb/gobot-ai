cmake_minimum_required(VERSION 3.16)

project(gobot-ai LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(gobot_core
    board/board.cpp
    engine/game_state.cpp
)
target_include_directories(gobot_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(gobot_core PUBLIC -Wall -Wextra)

add_executable(gobot main.cpp)
target_link_libraries(gobot PRIVATE gobot_core)

enable_testing()
# TODO: finish the testing implementation
