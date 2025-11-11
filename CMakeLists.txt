cmake_minimum_required(VERSION 3.25.0)

project(pon)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(
  GLOB_RECURSE
  SOURCES
  src/*.cc
)

add_executable(
  ${PROJECT_NAME}
  ${SOURCES}
)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)

target_compile_features(
  ${PROJECT_NAME}
  PRIVATE
  cxx_std_23
)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
  src
)

target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE
  SDL3::SDL3
)

target_compile_options(
  ${PROJECT_NAME}
  PRIVATE
  -Wall
  -Werror
  -Wpedantic
  -Wextra
  -flto
  -fno-exceptions
  -fno-rtti
)
