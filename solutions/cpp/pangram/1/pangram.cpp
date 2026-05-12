#include "pangram.h"
#include <unordered_set>
#include <cctype>

namespace pangram {

	// Option 1

	bool is_pangram(std::string str) {
		
		// Like Python's set(). A iterator that only takes unique values
		std::unordered_set<char> seen;

		for (auto c : str) {
			if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
				seen.insert(std::tolower(c)); // Used to ensure that values are treeated the same
			}
		}

		return seen.size() == 26;
	}

/* Option 2
	bool is_pangram(std::string str) {
		bool seen[26] = {};
		for (unsigned char c : str) {
			if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {

			// Subtracts the ASCII value of 'a' from the lowercase letter.
			// This works because letters are consecutive in the ASCII table:
			// a-a = 0 (idx), b-a = 1 (idx), .... 

				int idx = std::tolower(c) - 'a';
				if (idx >= 0 && idx < 26)
					seen[idx] = true;
			}
		}


		for (bool b : seen) {
			if (!b) {
				return false;
			}
		}
		return true;
	}

*/

}  // namespace pangram
