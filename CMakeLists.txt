cmake_minimum_required(VERSION 3.20)
project(Ray_cast CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Wswitch)
    add_link_options("$<$<CONFIG:DEBUG>:-fsanitize=address,undefined>")
endif()

add_executable(Ray_cast
        src/main.cpp
        src/Settings.h src/Player.cpp src/Player.h src/Vector.cpp src/Vector.h src/Map.cpp src/Map.h src/Time.cpp src/Time.h)

target_link_libraries(Ray_cast sfml-graphics)
target_compile_definitions(Ray_cast PRIVATE IMG_PATH="${CMAKE_SOURCE_DIR}/docs/")
target_compile_features(Ray_cast PRIVATE cxx_std_20)

ADD_CUSTOM_TARGET(DOCUMENTATION
        COMMAND ${CMAKE_COMMAND} -E echo_append "Building API Documentation..."
        COMMAND ${CMAKE_COMMAND} -E make_directory ${DOXYGEN_OUTPUT_DIR}
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Build
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E echo "Done.")