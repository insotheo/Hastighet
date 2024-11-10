cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Hastighet)

set(ENGINE_INCLUDE_DIRS 
${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/vendor/GLFW/include
${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/vendor/Glad/include
${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/vendor/ImGui
)

set(ENGINE_LIBS
opengl32
glfw
Glad
)

file(GLOB SOURCES 
    src/*.cpp
    src/Hastighet/*/*.cpp
    src/Platform/*/*.cpp

    ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/vendor/ImGui/ImGui/*.cpp
    ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/vendor/ImGui/ImGui/*/*.cpp
    ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/vendor/ImGui/ImGui/*.h
    ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/vendor/ImGui/ImGui/*/*.h
)

file(GLOB HEADERS
    src/*.h
    src/Hastighet/*/*.h
    src/Hastighet/*/*.hpp
    src/Platform/*/*.hpp
)

include_directories("${ENGINE_INCLUDE_DIRS}")

add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS} ${IMGUI_SOURCES})
add_library("${PROJECT_NAME}_st" STATIC ${SOURCES} ${HEADERS} ${IMGUI_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE src/)
target_include_directories("${PROJECT_NAME}_st" PRIVATE src/)

target_precompile_headers(${PROJECT_NAME} PRIVATE src/pch.h)
target_precompile_headers("${PROJECT_NAME}_st" PRIVATE src/pch.h)

target_link_libraries("${PROJECT_NAME}" PRIVATE "${ENGINE_LIBS}")
target_link_libraries("${PROJECT_NAME}_st" PRIVATE "${ENGINE_LIBS}")

target_compile_definitions("${PROJECT_NAME}" PRIVATE GLFW_INCLUDE_NONE)
target_compile_definitions("${PROJECT_NAME}_st" PRIVATE GLFW_INCLUDE_NONE)