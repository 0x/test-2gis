//
//  arg_parser.hpp
//  test
//
//  Created by Vitaly Koynov on 6/12/20.
//  Copyright © 2020 Vitaly Koynov. All rights reserved.
//

#pragma once

#include <vector>
#include <string>

class ArgParser
{
public:
	ArgParser(int argc, const char* argv[]);
	const std::string& getOption(std::string option_name) const;
	bool checkOption(std::string option_name) const;
	
private:
	std::vector<std::string> tokens;
};
