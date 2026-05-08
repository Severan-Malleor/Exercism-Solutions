#include "reverse_string.h"

namespace reverse_string {

	std::string reverse_string(std::string str) {
		std::string reversed{ "" };
		int total_length = static_cast<int>(str.length());

		for (int i = total_length - 1; i >= 0 ; --i) {
			reversed += str[i];
		}

		return reversed;
	}

}  // namespace reverse_string
