#include "acronym.h"
#include <cctype>

namespace acronym {

	std::string acronym(std::string str) {
		std::string acro = "";

		acro += std::toupper(str[0]);

		for (size_t i = 0; i < str.size(); ++i) {


			if (isspace(str[i]) && isalpha(str[i + 1])) {
				acro += std::toupper(str[i + 1]);
			}
			else if (str[i] == '-' || str[i] == '_') {
				if (isalpha(str[i + 1])) {
					acro += std::toupper(str[i + 1]);
				}
			}
		}

		return acro;

	}

}  // namespace acronym
