#include "nucleotide_count.h"
#include <stdexcept>

namespace nucleotide_count {

	std::map<char, int> count(std::string nucleotideString) {
		
		std::map<char, int> nucleotides = {
			{'A', 0},
			{'C', 0},
			{'G', 0},
			{'T', 0},
		};

		if (nucleotideString == "") {
			return nucleotides;
		}

		for (char c : nucleotideString) {
			// Use .contains if you only care about the existence of the key. It is more readable and clearly expresses your intent to the reader. (C++ 20 only)
			// Use .find if you plan to use the value associated with the key immediately after finding it.
			if (nucleotides.find(c) != nucleotides.end()) {
				nucleotides[c]++;
			}
			else {
				throw std::invalid_argument("Not a correct nucleotide string");
			}
		}

		return nucleotides;


		
	}

}  // namespace nucleotide_count
