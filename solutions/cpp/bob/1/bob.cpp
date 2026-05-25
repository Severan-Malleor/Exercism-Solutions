#include "bob.h"
#include <cctype>
#include <algorithm>

namespace bob {

	std::string hey(std::string statement) {

		
		auto isQuestion = false;
		auto hasLetters = false;
		auto allCaps = true;
		
		statement.erase(std::remove_if(statement.begin(), statement.end(), ::isspace), statement.end());

		auto lastIndex = statement.size() - 1;

		if (statement.empty()) {
			return "Fine. Be that way!";
		}
		else if (statement[lastIndex] == '?') {
			isQuestion = true;
		}



		for (auto c : statement) {
			if (std::isalpha(c)) {
				hasLetters = true;
				if (!std::isupper(c)) {
					allCaps = false;
					break;
				}
			}
		}

		auto isShouting = hasLetters && allCaps;

		if (!isShouting && isQuestion) {
			return "Sure.";
		}
		else if (isShouting && !isQuestion) {
			return "Whoa, chill out!";
		}
		else if (isShouting && isQuestion) {
			return "Calm down, I know what I'm doing!";
		}
		else {
			return "Whatever.";
		}



	}

}  // namespace bob
