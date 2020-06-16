//
//  arg_parser.cpp
//  test2gis
//
//  Created by Vitaly Koynov on 6/12/20.
//  Copyright © 2020 Vitaly Koynov. All rights reserved.
//

#include "arg_parser.hpp"
#include <stdexcept>

namespace testtask{
ArgParser::ArgParser(int argc, const char* argv[])
{
	std::copy(argv, argv + argc, std::back_inserter(tokens));
}

const std::string& ArgParser::getOption(const std::string& option_name) const
{
	auto it = std::find(tokens.begin(), tokens.end(), option_name);
	if (it != tokens.end() && std::next(it) != tokens.end())
	{
		return *std::next(it);
	}
	else
	{
		throw std::runtime_error("Could not find option for " + option_name);
	}
}

bool ArgParser::checkOption(const std::string& option_name) const
{
	auto it = std::find(tokens.begin(), tokens.end(), option_name);
	return it != tokens.end();
}
}  // namespace tasktask
