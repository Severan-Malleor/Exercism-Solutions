#include "scrabble_score.h"
#include <cctype>

namespace scrabble_score {

	int score(std::string word) {
		// static constexpr combines compile-time evaluation (constexpr) with fixed, 
		// program-lifetime memory storage (static). Using them together ensures that a 
		// constant value is computed at compile time and exists in a single,
		// permanent memory location rather than being re-created repeatedly on the stack
		static constexpr int scores[] = {
		//  A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z
			1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3,10, 1, 1, 1, 1, 4, 4, 8, 4,10
		};

		int sum = 0;
		for (auto c : word) {

            char upper_c = std::toupper(c);

            if (upper_c >= 'A' && upper_c <= 'Z') {
				// Since the letters A–Z are contiguous in ASCII, 
				// subtracting 'A' from any uppercase letter gives its 0-based index: 'A' - 'A' = 0 (65-65)
				// scores['A' - 'A' = 0] hence adding 1 to sum.
                sum += scores[upper_c - 'A'];
            }
        }
		return sum;
	}

}  // namespace scrabble_score
