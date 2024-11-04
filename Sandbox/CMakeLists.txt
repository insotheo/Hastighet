cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Sandbox)

file(GLOB SOURCES 
    src/*.cpp
)

file(GLOB HEADERS
    src/*.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(Sandbox Hastighet_st)
target_link_libraries(Sandbox Hastighet)