cmake_minimum_required(VERSION 3.4)

project (raytracing_simple)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
aux_source_directory(./src SOURCE_DIR)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin/)
add_executable(raytracing_simple ${SOURCE_DIR})