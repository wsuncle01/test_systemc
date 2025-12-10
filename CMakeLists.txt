cmake_minimum_required(VERSION 3.10)

project(Test VERSION 1.0)

set(CMAKE_VERBOSE_MAKEFILE on)

include_directories($(PROJECT_SOURCE_DIR)/inc/)
include_directories($ENV{SYSTEMC_HOME}/include/)
message(STATUS "SYSTEMC_HOME:$ENV{SYSTEMC_HOME}/include/")

link_directories($ENV{SYSTEMC_LIB})
message(STATUS "SYSTEMC_HOME:$ENV{SYSTEMC_LIB}")

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug)
endif()

add_compile_options(-Wno-narrowing -Wno-format -Wno-sign-compare)

add_executable(MAIN)
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
# file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.c")
target_sources(MAIN PUBLIC ${SOURCES})
target_link_libraries(MAIN -lsystemc)
target_link_libraries(MAIN -lstdc++)
target_link_libraries(MAIN -lm)
