//
//  file_guard.cpp
//  test2gis
//
//  Created by Vitaly Koynov on 6/15/20.
//  Copyright © 2020 Vitaly Koynov. All rights reserved.
//

#include "file_guard.hpp"
#include <stdexcept>

namespace testtask {
FileGuard::FileGuard(const std::string & filename)
	: file(filename)
{
	if (file.fail())
	{
		throw std::runtime_error("Could not open file: " + filename);
	}
}
	
std::ifstream& FileGuard::getIfstream()
{
	if (!file.is_open())
	{
		throw std::runtime_error("File if not open");
	}
	return file;
}
	
FileGuard::~FileGuard()
{
	file.close();
}
}  // namespace testtask
