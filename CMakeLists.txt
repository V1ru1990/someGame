cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(PROJECT_NAME someGame)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} src/main.cpp)

add_subdirectory(external/glfw)

target_link_libraries(${PROJECT_NAME} glfw)

add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad)