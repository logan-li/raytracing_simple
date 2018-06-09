cmake_minimum_required(VERSION 3.4)

project (raytracing_simple)

aux_source_directory(. SOURCE_DIR)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin/)
add_executable(raytracing_simple ${SOURCE_DIR})