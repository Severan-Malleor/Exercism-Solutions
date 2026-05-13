#include "hexadecimal.h"
#include <map>
#include <cmath>


/*
	From GIAC GSEC notes
	Find Total Example – Notice how there is 2 bytes or 4 places of hex that means ^0 - ^3:
	033D -> 829
	0 * 16^3
	3 * 16^2
	3 * 16^1
	D (13) * 16^0 (1)
	0 + 768 + 48 + 13 = 829

*/

namespace hexadecimal {

	int convert(std::string hexString) {

		int decimal{ 0 };

		std::map<char, int> hexMap = {
			{'0', 0},
			{'1', 1},
			{'2', 2},
			{'3', 3},
			{'4', 4},
			{'5', 5},
			{'6', 6},
			{'7', 7},
			{'8', 8},
			{'9', 9},
			{'a', 10},
			{'b', 11},
			{'c', 12},
			{'d', 13},
			{'e', 14},
			{'f', 15},
		};

		int indexPow = static_cast<int>(hexString.size()) - 1;

		for (auto c : hexString) {
			if (c >= '0' && c <= 'f') { // checking for alphanumerics between 1 and f
				decimal += hexMap[c] * std::pow(16, indexPow);
				indexPow--;
			}
			else {
				return 0;
			}
		}

		return decimal;
	}

}  // namespace hexadecimal
