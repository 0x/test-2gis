//
//  functions.hpp
//  test2gis
//
//  Created by Vitaly Koynov on 6/12/20.
//  Copyright © 2020 Vitaly Koynov. All rights reserved.
//

#pragma once

#include <string>
#include <fstream>

namespace testtask
{
	[[nodiscard]] std::size_t countWord(std::ifstream &file, const std::string &word);
	[[nodiscard]] std::uint32_t countChecksum(std::ifstream &file);
}  // namespace functions
