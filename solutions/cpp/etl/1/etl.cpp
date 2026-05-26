#include "etl.h"
#include <cctype>


namespace etl {

	std::map<char, int> transform(std::map<int, std::vector<char>> items) {

		std::map<char, int> newRes{};

		
		for (auto const& [key, value] : items) {
			for (auto v : value) {
				newRes[std::tolower(v)] = key;
			}
		}
		
		return newRes;
	}

}  // namespace etl
