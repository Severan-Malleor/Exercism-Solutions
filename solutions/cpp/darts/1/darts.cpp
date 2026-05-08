#include "darts.h"
#include <cmath>
namespace darts {

	int score(double x, double y) {
		int outer_circle_radius_max = 10;
		int middle_circle_radius = 5;
		int inner_circle_radius = 1;

		// REQUIRE(darts::score(7.1f, -7.1f) == 0)

		double distance = std::sqrt(x*x + y*y);

		if (distance > outer_circle_radius_max) {
			return 0;
		}
		else if (distance > middle_circle_radius && distance <= outer_circle_radius_max) {
			return 1;
		}
		else if (distance > inner_circle_radius && distance <= middle_circle_radius) {
			return 5;
		}
		else {
			return 10;
		}


		
	}

}  // namespace darts
