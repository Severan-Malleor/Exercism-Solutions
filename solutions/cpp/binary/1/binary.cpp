#include "binary.h"
#include <cmath>
#include <cctype>

namespace binary {

	int convert(std::string binaryString) {
		size_t strSize = binaryString.size();
		int sum = 0;

		for (size_t i = 0; i < strSize; ++i) {
			int power = strSize - 1 - i;
			if (binaryString[i] != '0' && binaryString[i] != '1') {
				return 0;
			}

				sum += (binaryString[i] - '0') << power;
			}

		return sum;
	}

}  // namespace binary

