cmake_minimum_required(VERSION 3.17)
project(concurrency_proj)

set(CMAKE_CXX_STANDARD 17)

# --------------------Chapter 2 Managing threads---------------
add_executable(2_3_wait_for_thread src/chapter_2/3_wait_for_thread.cpp)
add_executable(2_4_detaching_thread src/chapter_2/4_detaching_thread.cpp)
add_executable(2_5_return_thread_from_function src/chapter_2/5_return_thread_from_function.cpp)
add_executable(2_6_scoped_thread src/chapter_2/6_scoped_thread.cpp)
add_executable(2_8_spawn_threads_and_wait src/chapter_2/8_spawn_threads_and_wait.cpp)
add_executable(2_9_parallel_threads src/chapter_2/9_parallel_threads.cpp)
# -------------------Chapter 3 Sharing data between threads------
add_executable(3_1_using_mutex src/chapter_3/1_using_mutex.cpp)
add_executable(3_2_passing_reference_accident src/chapter_3/2_passing_reference_accident.cpp)
add_executable(3_5_thread_safe_stack src/chapter_3/5_thread_safe_stack.cpp)
add_executable(3_6_lock_and_lock_guard src/chapter_3/6_lock_and_lock_guard.cpp)
# -------------------Chapter 4 Synchronizing concurrent operations-------
add_executable(4_1_using_condition_variable src/chapter_4/1_using_condition_variable.cpp)