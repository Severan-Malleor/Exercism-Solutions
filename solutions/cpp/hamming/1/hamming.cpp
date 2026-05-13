#include "hamming.h"
#include <stdexcept>

namespace hamming {

	int compute(std::string strandOne, std::string strandTwo) {
		int mistakes{ 0 };

		if ((strandOne.empty() || strandOne.empty()) && (strandOne.size() == strandTwo.size())) {
			return 0;
		} else if (strandOne.size() == strandTwo.size()) {

			for (int i{ 0 }; i <= strandOne.size(); ++i) {
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
