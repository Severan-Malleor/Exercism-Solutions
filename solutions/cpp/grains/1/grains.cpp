#include "grains.h"
#include <cmath>

/*
	Think of it this way. each square is a bit (visually) and there is 64 of them.

	0000000000000000000000000000000000000000000000000000000000000000

	That means there is a 2^64 - 1 (unsigned long long / ULL) possible values. However we are doubling each bit ("square") which simply means
	to shift the bit left 
*/

namespace grains {

	unsigned long long square(int num) {

		// Same exact concept as subnet math amd bit masks. We are just shifting the bit over once which than doubles the num.
		// 00000001 (1) <- in a byte (8 bits) we have, going from L -> R. 128, 64, 32, 16, 8, 4, 2, 1
		// Each time we shift over 00000010 (2), 00000100 (4), 00001000 (8), ....
		// with 64 bits the number is much larger hence the 8 bit example
		return 1LL << (num - 1);
	}

	unsigned long long total() {

		// 0ULL is a 64-bit unsigned integer initialized to all 0 bits.
		// The bitwise NOT operator (~) flips every bit from 0 -> 1.
		// Result:
		// 1111111111111111111111111111111111111111111111111111111111111111
		// which equals 2^64 - 1.
		return ~0ULL;
	}

}  // namespace grains

