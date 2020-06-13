cmake_minimum_required(VERSION 3.10)


add_executable(test2gis_test arg_parser_test.cpp)


target_link_libraries(test2gis_test PUBLIC
	gtest_main
	core
)

file(COPY test_0b.txt
DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME test_test COMMAND test_test)