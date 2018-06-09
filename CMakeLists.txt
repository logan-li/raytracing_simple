cmake_minimum_required(VERSION 3.4)

project (raytracing)

aux_source_directory(. SOURCE_DIR)

add_executable(raytracing ${SOURCE_DIR})