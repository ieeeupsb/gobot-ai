cmake_minimum_required(VERSION 3.16)

project(gobot-ai LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# by the time we have cpp files, we need to update this to use cpp files
# also need to update INTERFACE to PUBLIC and PRIVATE
add_library(gobot_core INTERFACE)
target_include_directories(gobot_core INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(gobot_core INTERFACE -Wall -Wextra)
add_executable(gobot main.cpp)
target_link_libraries(gobot PRIVATE gobot_core)

enable_testing()
# TODO: finish the testing implementation
