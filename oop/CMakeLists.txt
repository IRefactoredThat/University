cmake_minimum_required(VERSION 3.15)

get_filename_component(task_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${task_name} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS
     ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
list(FILTER sources EXCLUDE REGEX "/(CMakeFiles|build)/")

add_executable(program ${sources})

target_include_directories(program PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
  target_compile_options(program PRIVATE -Wall -Wextra -Wpedantic)
endif()
