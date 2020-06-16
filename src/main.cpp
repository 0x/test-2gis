//
//  main.cpp
//  test2gis
//
//  Created by Vitaly Koynov on 6/12/20.
//  Copyright © 2020 Vitaly Koynov. All rights reserved.
//

#include "arg_parser.hpp"
#include "functions.hpp"
#include "file_guard.hpp"
#include <iostream>

namespace testtask{
auto help()
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
		testtask::ArgParser parser(argc, argv);
		
		if (parser.checkOption("-h"))
		{
			testtask::help();
			return 0;
		}
		const auto& filename = parser.getOption("-f");
		const auto&  mode = parser.getOption("-m");
		if (mode == "checksum")
		{
			testtask::FileGuard file(filename);
			
			std::cout << "Checksum: " << testtask::countChecksum(file.getIfstream()) << std::endl;
		}
		if (mode == "word")
		{
			const auto& word = parser.getOption("-v");
			testtask::FileGuard file(filename);
			
			std::cout << "Number of words " <<  word << ": "
			<< testtask::countWord(file.getIfstream(), word) << std::endl;
		}
	} catch (const std::exception &exception)
	{
		std::cerr << "Error: " << exception.what() << std::endl;
		testtask::help();
	}
	return 0;
}
