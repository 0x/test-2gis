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

struct ArgParserTest : public :: testing::Test
{
	virtual void SetUp() override
	{
		
	}
	
	virtual void TearDown() override {}
};

TEST_F(ArgParserTest, CheckOption)
{
	int argc = 2;
	const char *argv[] = {"test", "-f"};
	ArgParser parser(argc, argv);
	
	EXPECT_TRUE(parser.checkOption("-f"));
	EXPECT_FALSE(parser.checkOption("-m"));
}

TEST_F(ArgParserTest, CheckOptionEmptyArg)
{
	int argc = 1;
	const char *argv[] = {"test"};
	ArgParser parser(argc, argv);
	
	EXPECT_FALSE(parser.checkOption("-f"));
}

TEST_F(ArgParserTest, CheckGetArgument)
{
	int argc = 5;
	const char *argv[] = {"test", "-f", "file.txt", "-m", "word"};
	ArgParser parser(argc, argv);
	
	EXPECT_EQ(parser.getOption("-f"), "file.txt");
	EXPECT_EQ(parser.getOption("-m"), "word");
	EXPECT_ANY_THROW(parser.getOption("-v"));
}

TEST_F(ArgParserTest, CheckGetArgumentEmptyArg)
{
	int argc = 1;
	const char *argv[] = {"test"};
	ArgParser parser(argc, argv);
	
	EXPECT_ANY_THROW(parser.getOption("-f"));
}

TEST_F(ArgParserTest, CheckCountChecksum)
{
	std::ifstream file_0b("test_0b.txt");
	if (file_0b.fail())
	{
		throw std::runtime_error("Could not open file");
	}
	EXPECT_EQ(functions::countChecksum(file_0b), 0);
	
	file_0b.close();
}

TEST_F(ArgParserTest, CheckCountWordsEmptyFile)
{
	std::ifstream file_0b("test_0b.txt");
	if (file_0b.fail())
	{
		throw std::runtime_error("Could not open file");
	}
	
	EXPECT_EQ(functions::countWord(file_0b,"test"), 0);
	
	file_0b.close();
}
