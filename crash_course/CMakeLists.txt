cmake_minimum_required(VERSION 3.17)
project(crash_course)

#set cpp standard to 17.
set(CMAKE_CXX_STANDARD 17)

# add the directories of paths to search for include files
include_directories(part_1/include)

add_executable(crash_course
    part_1/src/main.cpp
    part_1/src/types/integer_formats.cpp
    part_1/src/types/float_formats.cpp
    part_1/src/types/arrays.cpp
)
