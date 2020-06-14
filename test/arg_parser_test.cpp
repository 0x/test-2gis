//
//  arg_parser_test.cpp
//  test
//
//  Created by Vitaly Koynov on 6/12/20.
//  Copyright © 2020 Vitaly Koynov. All rights reserved.
//

#include <gtest/gtest.h>
#include "arg_parser.hpp"
#include "functions.hpp"
#include <fstream>

struct Test2gis : public :: testing::Test
{
	virtual void SetUp() override
	{
		
	}
	
	virtual void TearDown() override {}
};

TEST_F(Test2gis, CheckOption)
{
	int argc = 2;
	const char *argv[] = {"test", "-f"};
	ArgParser parser(argc, argv);
	
	EXPECT_TRUE(parser.checkOption("-f"));
	EXPECT_FALSE(parser.checkOption("-m"));
}

TEST_F(Test2gis, CheckOptionEmptyArg)
{
	int argc = 1;
	const char *argv[] = {"test"};
	ArgParser parser(argc, argv);
	
	EXPECT_FALSE(parser.checkOption("-f"));
}

TEST_F(Test2gis, GetArgument)
{
	int argc = 5;
	const char *argv[] = {"test", "-f", "file.txt", "-m", "word"};
	ArgParser parser(argc, argv);
	
	EXPECT_EQ(parser.getOption("-f"), "file.txt");
	EXPECT_EQ(parser.getOption("-m"), "word");
	EXPECT_ANY_THROW(parser.getOption("-v"));
}

TEST_F(Test2gis, GetArgumentEmptyArg)
{
	int argc = 1;
	const char *argv[] = {"test"};
	ArgParser parser(argc, argv);
	
	EXPECT_ANY_THROW(parser.getOption("-f"));
}

TEST_F(Test2gis, CountChecksum0bit)
{
	std::ifstream file_0bit("test_empty.txt");
	if (file_0bit.fail())
	{
		throw std::runtime_error("Could not open file");
	}
	EXPECT_EQ(functions::countChecksum(file_0bit), 0);
	
	file_0bit.close();
}

TEST_F(Test2gis, CountChecksum32bit)
{
	std::ifstream file_abcd("test_abcd.txt");
	if (file_abcd.fail())
	{
		throw std::runtime_error("Could not open file");
	}
	EXPECT_EQ(functions::countChecksum(file_abcd), 1684234849)
	<< "Checksum of a 32bit word is equal to that word";
	
	file_abcd.close();
}

TEST_F(Test2gis, CountChecksum40bit)
{
	std::ifstream file_abcde("test_abcde.txt");
	if (file_abcde.fail())
	{
		throw std::runtime_error("Could not open file");
	}
	EXPECT_NE(functions::countChecksum(file_abcde), 1684234849)
	<< "Bits are not lost, if a word is shorter than 32 bits";
	
	file_abcde.close();
}

TEST_F(Test2gis, CountWordsEmptyFile)
{
	std::ifstream file_empty("test_empty.txt");
	if (file_empty.fail())
	{
		throw std::runtime_error("Could not open file");
	}
	
	EXPECT_EQ(functions::countWord(file_empty,"test"), 0);
	
	file_empty.close();
}

TEST_F(Test2gis, CountWordsZeroWords)
{
	std::ifstream file_0words("test_0words.txt");
	if (file_0words.fail())
	{
		throw std::runtime_error("Could not open file");
	}
	
	EXPECT_EQ(functions::countWord(file_0words,"test"), 0);
	
	file_0words.close();
}

TEST_F(Test2gis, CountWords5Words)
{
	std::ifstream file_5words("test_5words.txt");
	if (file_5words.fail())
	{
		throw std::runtime_error("Could not open file");
	}
	
	EXPECT_EQ(functions::countWord(file_5words,"test"), 5);
	
	file_5words.close();
}
