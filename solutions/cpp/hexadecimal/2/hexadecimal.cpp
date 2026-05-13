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

		for (char c : hexString) {
			int value{ 0 };

			if (c >= '0' && c <= '9') { // Checks if the char is numberic
				value = c - '0'; // a common technique used to convert a character digit into its corresponding integer value
			}
			else if (c >= 'a' && c <= 'f') { //Checks if char is a-f the last 6 values of base 16 (Hex)
				value = c - 'a' + 10; // Convert hex letter ('a'-'f') into decimal value (10-15) using ASCII math
			}
			else {
				return 0;
			}

			decimal = decimal * 16 + value;
		}

		return decimal;

	}

}  // namespace hexadecimal


