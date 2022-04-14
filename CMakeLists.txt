cmake_minimum_required(VERSION 3.20)
project(Step)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Step
        main.cpp
        Settings.h Player.cpp Player.h Vector.cpp Vector.h Map.cpp Map.h Time.cpp Time.h)

target_link_libraries(Step sfml-graphics)