cmake_minimum_required(VERSION 3.8)
project(grade_need)

set(CMAKE_C_STANDARD 11)
set(GCC_ENABLE_WARNINGS "-Wall -Werror -lm -Wno-unused-result")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_ENABLE_WARNINGS}" )

set(SOURCE_FILES main.c)
add_executable(grade_need ${SOURCE_FILES})