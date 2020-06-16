//
//  file_guard.hpp
//  test2gis
//
//  Created by Vitaly Koynov on 6/15/20.
//  Copyright © 2020 Vitaly Koynov. All rights reserved.
//

#pragma once

#include <string>
#include <fstream>

namespace testtask {
class FileGuard
{
public:
	explicit FileGuard(const std::string & filename);
	std::ifstream& getIfstream();
	
	FileGuard(const FileGuard&) = delete;
	FileGuard& operator=(const FileGuard&) = delete;
	FileGuard(FileGuard&&) = delete;
	FileGuard& operator=(FileGuard&&) = delete;
	
	~FileGuard();
	
private:
    std::ifstream file;
};
}  // namespace testtask
              
