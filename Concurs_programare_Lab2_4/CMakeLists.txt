cmake_minimum_required(VERSION 4.1)

project(gabi C)

set(CMAKE_C_STANDARD 11)


add_executable(gabi main.c)

include_directories(concurs_lib)

add_subdirectory(concurs_lib)

add_subdirectory(Google_tests)

target_link_libraries(gabi Concurs123_lib)


