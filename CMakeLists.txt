cmake_minimum_required(VERSION 4.1)
project(noalloc)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_library(noalloc_lib 
    SHARED
    src/noalloc_guard.cpp
)

target_include_directories(noalloc_lib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(noalloc_lib PRIVATE -Wall -Wextra -Werror -pedantic)


add_executable(ex_capability examples/ex_capability.cpp)
target_link_libraries(ex_capability PRIVATE noalloc_lib)

add_executable(ex_compile_time examples/ex_compile_time.cpp)
target_link_libraries(ex_compile_time PRIVATE noalloc_lib)

add_executable(ex_runtime_guard examples/ex_runtime_guard.cpp)
target_link_libraries(ex_runtime_guard PRIVATE noalloc_lib)
