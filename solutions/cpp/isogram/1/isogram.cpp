#include "isogram.h"
#include <set>
#include <cctype>
namespace isogram {

	bool is_isogram(std::string str) {
		
		std::set<char> seen{};

		for (auto c : str) {

			if (isspace(c) || c == '-') {
				continue;
			}

			auto [i, success] = seen.insert(tolower(c));
			
			if (!success) {
				return false;
			}
		}

		return true;

	}

}  // namespace isogram
