cmake_minimum_required(VERSION 3.29)
project(sfc CXX)

set(CMAKE_CXX_STANDARD 26)
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


set(BENCHMARK_USE_BUNDLED_GTEST false)
set(BENCHMARK_ENABLE_GTEST_TESTS false)
add_subdirectory(benchmark)

add_executable(sfc-benchmark
               benchmark_src/example.cpp
              )
target_compile_options(sfc-benchmark PRIVATE "$<$<CONFIG:RELEASE>:-march=native>")
target_include_directories(sfc-benchmark PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(sfc-benchmark PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/benchmark/include)
target_link_libraries(sfc-benchmark benchmark::benchmark)
