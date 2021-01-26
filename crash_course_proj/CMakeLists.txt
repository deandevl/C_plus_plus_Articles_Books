cmake_minimum_required(VERSION 3.17)
project(crash_course_proj)

#set cpp standard to 17.
set(CMAKE_CXX_STANDARD 17)

# 2 Types
# types::integer_formats
add_executable(integer_formats part_1/src/types/integer_formats.cpp)

# types::float_formats
add_executable(float_formats part_1/src/types/float_formats.cpp)

# types::arrays
add_executable(arrays part_1/src/types/arrays.cpp)

# 12 Utilities
# Date and Time
add_executable(chrono_time part_1/src/12_utilities/date_and_time/three_chrono_times_21.cpp)
add_executable(chrono_duration part_1/src/12_utilities/date_and_time/duration_22_23_24.cpp)

# 19 Concurrency
# concurrent::async_interaction
add_executable(async_interaction part_1/src/19_concurrency/async_tasks/async_interaction_1_4_5.cpp)

# concurrent::async_factors
add_executable(async_factors part_1/src/19_concurrency/async_tasks/async_factors_7_8.cpp)

# concurrent::goat_rodeo_atomic
add_executable(goat_rodeo_atomic part_1/src/19_concurrency/sharing_coordinate/goat_rodeo_atomic_13.cpp)

# concurrent::goat_rodeo_condition_var
add_executable(goat_rodeo_condition_var part_1/src/19_concurrency/sharing_coordinate/goat_rodeo_condition_var_14.cpp)

# concurrent::goat_rodeo_mutex
add_executable(goat_rodeo_mutex part_1/src/19_concurrency/sharing_coordinate/goat_rodeo_mutex_11.cpp)


