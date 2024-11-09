cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Hastighet)

set(ENGINE_INCLUDE_DIRS 
${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/vendor/include
)

set(ENGINE_LIB_DIRS
${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/vendor/lib
)

set(ENGINE_LIBS
opengl32
${ENGINE_LIB_DIRS}/glfw3.lib
)

file(GLOB SOURCES 
    src/*.cpp
    src/Hastighet/*/*.cpp
    src/Platform/*/*.cpp
)

file(GLOB HEADERS
    src/*.h
    src/Hastighet/*/*.h
    src/Hastighet/*/*.hpp
    src/Platform/*/*.hpp
)

include_directories("${ENGINE_INCLUDE_DIRS}")
link_directories("${ENGINE_LIB_DIRS}")

add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})
add_library("${PROJECT_NAME}_st" STATIC ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC src/Hastighet)
target_include_directories("${PROJECT_NAME}_st" PUBLIC src/Hastighet)

target_precompile_headers(${PROJECT_NAME} PRIVATE src/pch.h)
target_precompile_headers("${PROJECT_NAME}_st" PRIVATE src/pch.h)

target_link_libraries("${PROJECT_NAME}" PRIVATE "${ENGINE_LIBS}")
target_link_libraries("${PROJECT_NAME}_st" PRIVATE "${ENGINE_LIBS}")