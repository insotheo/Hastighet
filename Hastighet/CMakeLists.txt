cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Hastighet)

file(GLOB SOURCES 
    src/*.cpp
)

file(GLOB HEADERS
    src/*.h
)

add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})
add_library("${PROJECT_NAME}_st" STATIC ${SOURCES} ${HEADERS})
