cmake_minimum_required(VERSION 3.10)

project(test2gis)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()
add_subdirectory(googletest)

set(HEADERS
	include/arg_parser.hpp
	include/functions.hpp
)

set(SOURCES
	src/arg_parser.cpp
	src/functions.cpp
)

add_library(core ${HEADERS} ${SOURCES})

#target_compile_features(core PRIVATE cxx_std_17)
target_compile_options(core PRIVATE -Wall)
target_include_directories(core PUBLIC include)

add_executable(test2gis src/main.cpp)

target_link_libraries(test2gis core)

add_subdirectory(test)

