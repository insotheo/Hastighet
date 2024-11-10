cmake_minimum_required(VERSION 3.10)

project(Glad)

file(GLOB SOURCES
src/glad.c)

include_directories("include/")

find_package(OpenGL REQUIRED)

add_library("${PROJECT_NAME}" STATIC "${SOURCES}")

target_link_libraries("${PROJECT_NAME}" PRIVATE OpenGL::GL)
set_target_properties("${PROJECT_NAME}" PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED YES)