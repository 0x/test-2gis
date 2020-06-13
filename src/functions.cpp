//
//  test_functions.cpp
//  test
//
//  Created by Vitaly Koynov on 6/12/20.
//  Copyright © 2020 Vitaly Koynov. All rights reserved.
//

#include "functions.hpp"
#include <numeric>

namespace functions
{
	size_t countWord(std::ifstream &file, const std::string &word)
	{
		// Consider that the words in the text are separated by spaces
		return std::accumulate(std::istream_iterator<std::string>(file),
						   std::istream_iterator<std::string>(), 0,
						   [&word](const int &count, const std::string str)
		{
			return (str == word)?(count + 1):count;
		});
	}

	uint32_t countChecksum(std::ifstream &file)
	{
		uint32_t check_sum{ 0L };
		unsigned int shift{ 0 };
		for (auto word = file.get(); file; word = file.get())
		{
			check_sum += (word << shift);
			shift += 8;
			if (shift == 32)
			{
				shift = 0;
			}
		}
		return check_sum;
	}
}  // namespace functions
