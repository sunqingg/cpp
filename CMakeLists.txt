cmake_minimum_required(VERSION 3.23)
project(test1111)

set(CMAKE_CXX_STANDARD 14)

#add_executable(test stack_queue.cpp stack_queue.h cmake-build-debug/test.h Queue_use.cpp cmake-build-debug/Queue_use.h sunTest.cpp sunTest.h algo/stack.cpp algo/print_utils.cpp algo/linkedlist_stack.cpp algo/listedlist_queue.cpp)
include_directories(./include)
add_subdirectory(algo)
add_executable(listedlist_queue algo/listedlist_queue.cpp)
add_executable(linkedlist_stack algo/linkedlist_stack.cpp)
add_executable(deque algo/deque.cpp)
add_executable(linkedlist_queue algo/linkedlist_queue.cpp)
add_executable(hash_map_chaining algo/hash_map_chaining.cpp)