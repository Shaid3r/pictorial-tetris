cmake_minimum_required(VERSION 2.4)
set(EXECUTABLE_NAME "Tetris")
project(${EXECUTABLE_NAME})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
#set(SFML_STATIC_LIBRARIES TRUE)

#find_package(SFML 2.5 COMPONENTS graphics audio system REQUIRED)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(${EXECUTABLE_NAME} ${SOURCES})
target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-window sfml-system)
