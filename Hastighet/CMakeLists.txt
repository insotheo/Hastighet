cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Hastighet)

file(GLOB SOURCES 
    src/*.cpp
    src/Hastighet/*/*.cpp
)

file(GLOB HEADERS
    src/*.h
    src/Hastighet/*/*.h
    src/Hastighet/*/*.hpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})
add_library("${PROJECT_NAME}_st" STATIC ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC src/Hastighet)
target_include_directories("${PROJECT_NAME}_st" PUBLIC src/Hastighet)