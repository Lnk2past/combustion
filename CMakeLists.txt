cmake_minimum_required(VERSION 3.25.1)

project(combustion)

find_package(Python COMPONENTS Interpreter Development)

find_package(fmt REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(pybind11 REQUIRED)
find_package(spdlog REQUIRED)

add_compile_options(-std=c++20)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
