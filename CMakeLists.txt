cmake_minimum_required(VERSION 3.6)
set(EXECUTABLE_NAME "Tetris")
project(${EXECUTABLE_NAME})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(${EXECUTABLE_NAME} ${SOURCES} include/State.h src/MenuState.cpp include/MenuState.h)
target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-window sfml-system)