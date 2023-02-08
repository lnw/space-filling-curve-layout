cmake_minimum_required(VERSION 3.20.0)
project(sfc CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_VERBOSE_MAKEFILE false)

# set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-fix")

add_executable(sfc-example
               src/example.cpp
               src/hilbert-layout.h
               src/hilbert.h
               src/morton-layout.h
               src/morton.h
              )

target_include_directories(sfc-example PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(sfc-example PRIVATE "$<$<CONFIG:DEBUG>:-Wall;-Wshadow;-Wpedantic>")
target_compile_options(sfc-example PRIVATE "$<$<CONFIG:RELEASE>:-march=native>")
