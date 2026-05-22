#include "collatz_conjecture.h"
#include <stdexcept>

namespace collatz_conjecture {

	// Counts how many steps it takes to reach 1 following the Collatz rules:
	//   - If the number is even, divide it by 2.
	//   - If the number is odd, multiply it by 3 and add 1.
	// The function calls itself (recursion) each step, adding 1 to the count
	// each time until the number reaches 1, at which point we return 0 and
	// the total count unwinds back up through all the previous calls.
	int steps(int num) {
		if (num <= 0) {
			throw std::domain_error("Number must be 1 or more.");
		}
		if (num == 1) {
			return 0; // Base case: we've reached 1, no more steps needed.
		}
		if (num % 2 == 0) {
			return 1 + steps(num / 2); // Even: take one step, then keep going with num / 2.
		}
		return 1 + steps((3 * num) + 1); // Odd: take one step, then keep going with (3 * num) + 1.
	}

}  // namespace collatz_conjecture
