cmake_minimum_required(VERSION 3.29)
project(laravel_lang)

set(CMAKE_CXX_STANDARD 26)

find_package(nlohmann_json 3.2.0 REQUIRED)

add_executable(
        compiler
        compiler.cpp
        compiler/compiler.h
        compiler/compiler.cpp
)

target_link_libraries(compiler PRIVATE nlohmann_json::nlohmann_json)