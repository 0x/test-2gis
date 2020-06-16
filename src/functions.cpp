//
//  test_functions.cpp
//  test2gis
//
//  Created by Vitaly Koynov on 6/12/20.
//  Copyright © 2020 Vitaly Koynov. All rights reserved.
//

#include "functions.hpp"
#include <numeric>

namespace testtask{
std::size_t countWord(std::ifstream& file, const std::string& word)
{
	// Consider that the words in the text are separated by spaces
	// or punctuation character: !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
	return std::accumulate(std::istream_iterator<std::string>(file),
						   std::istream_iterator<std::string>(), 0,
						   [&word](const auto& count, const auto& str)
	{
		// Simple case
		if (str == word)
		{
			return count + 1;
		}
		// Punctuation case
		auto local_count = 0;
		auto iter = str.begin();
		while (iter != str.end())
		{
			auto iter_punct = std::find_if(iter, str.end(), [](const auto& elem) {return std::ispunct(elem);});
			
			std::string build_word{iter, iter_punct};
			
			if (build_word == word)
			{
				local_count++;
			}
			
			// Change the iteratror to an iterator after the punctuation character
			if (iter_punct != str.end() && std::next(iter_punct) != str.end())
			{
				iter = std::next(iter_punct);
			}
			else
			{
				iter = str.end();
			}
		}
		return count + local_count;
	});
}

std::uint32_t countChecksum(std::ifstream& file)
{
	std::uint32_t check_sum = 0;
	auto shift = 0u;
	for (auto word = file.get(); file; word = file.get())
	{
		// Calculate as little-endian
		// Returns in the native representation of the machine
		check_sum += (word << shift);
		shift += 8;
		if (shift == 32)
		{
			shift = 0;
		}
	}
	return check_sum;
}
}  // namespace testtask
