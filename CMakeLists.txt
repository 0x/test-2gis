cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(test2gis)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(HEADERS
	include/arg_parser.hpp
	include/functions.hpp
	include/file_guard.hpp
)

set(SOURCES
	src/arg_parser.cpp
	src/functions.cpp
	src/file_guard.cpp
)

add_library(core ${HEADERS} ${SOURCES})

target_compile_options(core PRIVATE -Wall)
target_include_directories(core PUBLIC include)

add_executable(test2gis src/main.cpp)

target_link_libraries(test2gis core)

option(ENABLE_TESTS "Enable tests" ON)
if (${ENABLE_TESTS})
	message(STATUS "Building with tests")
    	enable_testing()
	add_subdirectory(googletest)
	add_subdirectory(test)
endif()


