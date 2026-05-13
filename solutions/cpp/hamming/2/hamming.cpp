#include "hamming.h"
#include <stdexcept>

namespace hamming {

	unsigned int compute(std::string strandOne, std::string strandTwo) {
		unsigned int mistakes{ 0 };
		unsigned int strandOneSize = static_cast<int>(strandOne.size());
		unsigned int strandTwoSize = static_cast<int>(strandTwo.size());

		if ((strandOne.empty() || strandOne.empty()) && (strandOneSize == strandTwoSize)) {
			return 0;
		} else if (strandOneSize == strandTwoSize) {

			for (unsigned int i{ 0 }; i < strandOneSize; ++i) {
				if (strandOne[i] != strandTwo[i]) {
					mistakes += 1;
				}
			}

			return mistakes;
		}
		else {
			throw std::domain_error("Strands are not of equal lengths");
		}
	}

}  // namespace hamming
