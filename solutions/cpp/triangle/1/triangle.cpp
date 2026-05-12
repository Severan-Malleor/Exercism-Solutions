#include "triangle.h"
#include <stdexcept>

namespace triangle {

	flavor kind(double sideOne, double sideTwo, double sideThree) {
		if (sideOne <= 0 || sideTwo <= 0 || sideThree <= 0) {
			throw std::domain_error("sides must be positive");
		}
		/*
			In mathematics, the triangle inequality states that for any triangle, 
			the sum of the lengths of any two sides must be greater than or equal to the length of the remaining side.
		*/
		if (sideOne + sideTwo <= sideThree || sideOne + sideThree <= sideTwo || sideTwo + sideThree <= sideOne) {
			throw std::domain_error("triangle inequality violated");
		}
		if (sideOne == sideTwo && sideOne == sideThree) {
			return flavor::equilateral;
		}
		else if (sideOne != sideTwo && sideOne != sideThree && sideTwo != sideThree) {
			return flavor::scalene;
		}
		else {
			return flavor::isosceles;
		}
	}

}  // namespace triangle
