//
//  main.cpp
//  test
//
//  Created by Vitaly Koynov on 6/12/20.
//  Copyright © 2020 Vitaly Koynov. All rights reserved.
//
#include "arg_parser.hpp"
#include "functions.hpp"
#include <iostream>
#include <fstream>

namespace functions{
void help()
{
	std::cout << "Usage: " << " [options]\n"
	<< "Options:\n"
	<< "\t-f <file> -m words -v <word>\t\tPrint number of words <word> in the <file>.\n"
	<< "\t-f <file> -m checksum       \t\tPrint checksum of the <file>.\n"
	<< "\t-h                          \t\tDisplay this information.\n"
	<< std::endl;
}
}

int main(int argc, const char * argv[])
{
	try
	{
		ArgParser parser(argc, argv);
		
		if (parser.checkOption("-h"))
		{
			functions::help();
			return 0;
		}
		std::string filename = parser.getOption("-f");
		std::string mode = parser.getOption("-m");
		if (mode == "checksum")
		{
			std::ifstream file(filename);
			if (file.fail())
			{
				throw std::runtime_error("Could not open file");
			}
			
			std::cout << "Checksum: " << functions::countChecksum(file) << std::endl;
			
			file.close();
		}
		if (mode == "word")
		{
			std::string word = parser.getOption("-v");
			std::ifstream file(filename);
			if (file.fail())
			{
				throw std::runtime_error("Could not open file");
			}
			
			std::cout << "Number of words " <<  word << ": "
			<< functions::countWord(file, word) << std::endl;
			
			file.close();
		}
	} catch (const std::exception &exception)
	{
		std::cerr << "Error: " << exception.what() << std::endl;
		functions::help();
	}
	return 0;
}
