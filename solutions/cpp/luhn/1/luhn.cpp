#include "luhn.h"
#include <string>

namespace luhn {

	bool valid(std::string numbers) {
		
		if (numbers.length() <= 1) {
			return false;
		}

		/*
			The "erase-remove idiom" is the standard approach. 
			std::remove shifts the non-space characters to the front,
			and erase removes the leftover "junk" at the end of the string.
			Standard C++ (C++11 to C++17)
		*/
		numbers.erase(std::remove(numbers.begin(), numbers.end(), ' '), numbers.end());

		size_t total_length = numbers.length();

		if (total_length <= 1) {
			return false;
		}

		int sum{ 0 };

		// iterate through the string in reverse, starting from the second to last character and stepping by 2
		for (size_t i = total_length -2; i < total_length; i -= 2) {

			// Standard C++ (C++11 to C++17) - convert char to int by subtracting '0' from the char which return the integer value of the char
			int number = numbers[i] - '0';

			// Testing for non-digits
			if (number < 0 || number > 9) {
				return false;
			}

			int doubling = number * 2;

			if (doubling > 9) {
				doubling -= 9;
			}

			// Replacing the doubled value in place by index
			// Also standard C++ (C++11 to C++17) - convert int back to char by adding '0' to the int which return the char value of the int
			numbers[i] = doubling + '0';

		}
		
		// Range-based for loop used to iterate through each character (char) within a collection, which is likely a string or a character array.
		for (char c : numbers) {

			// Testing for non-digits
			if (c < '0' || c > '9') {
				return false;
			}

			sum += c - '0';
		}

		if (sum % 10 == 0) {
			return true;
		}
		else {
			return false;
		}


		
	}

}  // namespace luhn
