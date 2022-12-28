cmake_minimum_required(VERSION 3.21)

project(TestingCmakeWorld)

# use the c++ 17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# any compiler flahs that should be used
set(CMAKE_CXX_FLAGS "-O2 -Wall")

file(GLOB CPP_SOURCE 
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(main ${CPP_SOURCE})
