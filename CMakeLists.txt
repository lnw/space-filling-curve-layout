cmake_minimum_required(VERSION 3.20.0)
project(sfc CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_VERBOSE_MAKEFILE true)

# set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-fix")

add_executable(sfc
               src/main.cpp
               src/morton.h
               src/hilbert.h
              )

target_include_directories(sfc PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(sfc PRIVATE "$<$<CONFIG:DEBUG>:-Wall;-Wshadow;-Wpedantic>")
target_compile_options(sfc PRIVATE "$<$<CONFIG:RELEASE>:-march=native>")
