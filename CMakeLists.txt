cmake_minimum_required(VERSION 3.28.3)
project(dywoqtest)

add_library(dywoqtest INTERFACE)

target_include_directories(dywoqtest
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
