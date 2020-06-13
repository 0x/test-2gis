//
//  arg_parser.cpp
//  test
//
//  Created by Vitaly Koynov on 6/12/20.
//  Copyright © 2020 Vitaly Koynov. All rights reserved.
//

#include "arg_parser.hpp"
#include <stdexcept>

ArgParser::ArgParser(int argc, const char* argv[])
{
	for (auto it = 0; it < argc; it++)
	{
		tokens.push_back(argv[it]);
	}
}

const std::string &ArgParser::getOption(std::string option_name) const
{
	auto it = std::find(tokens.begin(), tokens.end(), option_name);
	if (it != tokens.end() && std::next(it) != tokens.end())
	{
		return *std::next(it);
	}
	else
	{
		throw std::runtime_error("Could not find arguments");
	}
}

bool ArgParser::checkOption(std::string option_name) const
{
	auto it = std::find(tokens.begin(), tokens.end(), option_name);
	if (it != tokens.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}
