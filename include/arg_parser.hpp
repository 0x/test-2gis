//
//  arg_parser.hpp
//  test2gis
//
//  Created by Vitaly Koynov on 6/12/20.
//  Copyright © 2020 Vitaly Koynov. All rights reserved.
//

#pragma once

#include <vector>
#include <string>

namespace testtask{
class ArgParser
{
public:
	ArgParser(int argc, const char* argv[]);
	const std::string& getOption(const std::string& option_name) const;
	bool checkOption(const std::string& option_name) const;
	
private:
	std::vector<std::string> tokens;
};
}  // namespace testtask
