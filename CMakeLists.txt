cmake_minimum_required(VERSION 3.22)
project(Proyecto)

set(CMAKE_CXX_STANDARD 14)

# Search all the .cpp files and add them to a variable
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
add_executable(${PROJECT_NAME} src/Proyecto.cpp ${SOURCE_FILES})
