//
//  arg_parser_test.cpp
//  test
//
//  Created by Vitaly Koynov on 6/12/20.
//  Copyright © 2020 Vitaly Koynov. All rights reserved.
//

#include <gtest/gtest.h>
#include <arg_parser.hpp>
#include <functions.hpp>
#include <file_guard.hpp>
#include <fstream>

TEST(Test2gis, CheckOption)
{
	int argc = 2;
	const char *argv[] = {"test", "-f"};
	testtask::ArgParser parser(argc, argv);
	
	EXPECT_TRUE(parser.checkOption("-f"));
	EXPECT_FALSE(parser.checkOption("-m"));
}

TEST(Test2gis, CheckOptionEmptyArg)
{
	int argc = 1;
	const char *argv[] = {"test"};
	testtask::ArgParser parser(argc, argv);
	
	EXPECT_FALSE(parser.checkOption("-f"));
}

TEST(Test2gis, GetArgument)
{
	int argc = 5;
	const char *argv[] = {"test", "-f", "file.txt", "-m", "word"};
	testtask::ArgParser parser(argc, argv);

	ASSERT_TRUE(parser.checkOption("-f"));
	ASSERT_TRUE(parser.checkOption("-m"));
	
	EXPECT_EQ(parser.getOption("-f"), "file.txt");
	EXPECT_EQ(parser.getOption("-m"), "word");
}

TEST(Test2gis, GetArgumentEmptyArg)
{
	{
		//create_parser(1, "test");
	int argc = 1;
	const char *argv[] = {"test"};
	testtask::ArgParser parser(argc, argv);
	
	EXPECT_ANY_THROW(parser.getOption("-f"));
	}
	{
	int argc1 = 5;
	const char *argv1[] = {"test", "-f", "file.txt", "-m", "word"};
		testtask::ArgParser parser(argc1, argv1);
	
	EXPECT_ANY_THROW(parser.getOption("-v"));
	}
}

TEST(Test2gis, OpenExistingFile)
{
	testtask::FileGuard file("test_empty.txt");
	
	//EXPECT_NO_THROW();
}

TEST(Test2gis, OpenNonExistingFile)
{
	
	EXPECT_ANY_THROW(testtask::FileGuard("test_non_exist.txt"));
}

TEST(Test2gis, CountChecksum0bit)
{
	std::ifstream file( "test_empty.txt", std::ios::binary | std::ios::ate);
	
	ASSERT_EQ(file.tellg(),0);
	file.close();
	
	testtask::FileGuard file_empty("test_empty.txt");
	EXPECT_EQ(testtask::countChecksum(file_empty.getIfstream()), 0);
}

TEST(Test2gis, CountChecksum32bit)
{
	testtask::FileGuard file("test_abcd.txt");

	EXPECT_EQ(testtask::countChecksum(file.getIfstream()), 1684234849)
	<< "Checksum of a 32bit word is equal to that word";
}

TEST(Test2gis, CountChecksum40bit)
{
	testtask::FileGuard file("test_abcde.txt");

	EXPECT_NE(testtask::countChecksum(file.getIfstream()), 1684234849)
	<< "Bits are not lost, if a word is shorter than 32 bits";
}

TEST(Test2gis, CountWordsEmptyFile)
{
	testtask::FileGuard file("test_empty.txt");
	
	EXPECT_EQ(testtask::countWord(file.getIfstream(),"test"), 0);
}

TEST(Test2gis, CountWordsZeroWords)
{
	testtask::FileGuard file("test_0words.txt");
	
	EXPECT_EQ(testtask::countWord(file.getIfstream(),"test"), 0);
}

TEST(Test2gis, CountWords5Words)
{
	testtask::FileGuard file("test_5words.txt");
	
	EXPECT_EQ(testtask::countWord(file.getIfstream(),"test"), 5);
}


