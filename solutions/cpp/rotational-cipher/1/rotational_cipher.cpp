#include "rotational_cipher.h"

/*
	The algorithm is quite simple:

	* we take the distance from the char from the base of either 'A' or 'a'
	* we add the rotation to the difference
	* We than use modulo (%) to find the remaining letters from the base than add the remaining rotation count to the base.
	* Therefore, the modulo is our "wrap around"
	
	When we add the rotation to the difference
	we are using up the distance from char to 'z' or 'Z' (without going over the decimal for 'z' or 'Z' 
	and using modulo to find the remaining count than add from base to "wrap around" and use remaining count.
	
*/

namespace rotational_cipher {

	std::string rotate(std::string plainText, int rotation) {

		std::string encodedText;

		if (rotation == 0) {
			return plainText;
		}
		else {
			for (auto c : plainText) {
				if (isspace(c) || ispunct(c) || isdigit(c)) {
					encodedText += c;
				}
				else {
					if (islower(c)) {
						encodedText += (c - 'a' + rotation) % 26 + 'a';
					}
					else if (isupper(c)) {
						encodedText += (c - 'A' + rotation) % 26 + 'A';
					}
				}
			}
		}

		return encodedText;
	}

}  // namespace rotational_cipher
