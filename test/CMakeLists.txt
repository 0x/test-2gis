add_executable(test2gis_test test2gis_test.cpp)

target_link_libraries(test2gis_test PUBLIC
	gtest_main
	core
)

file(COPY 
	test_empty.txt 
	test_0words.txt
	test_5words.txt
	test_abcd.txt
	test_abcde.txt
	test_10words_punct.txt
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)

add_test(NAME test2gis_test COMMAND test2gis_test)