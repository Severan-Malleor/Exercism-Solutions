#include "armstrong_numbers.h"
#include <string>
#include <cmath>

namespace armstrong_numbers {

	bool is_armstrong_number(int num) {
		std::string numString = std::to_string(num);
		int numSize = static_cast<int>(numString.size());
		int totalSum{ 0 };

		for (int i{ 0 }; i < numSize; ++i) {
			int value = numString[i] - '0';
			totalSum += std::pow(value, numSize);
		}

		return num == totalSum;
	}

}  // namespace armstrong_numbers
