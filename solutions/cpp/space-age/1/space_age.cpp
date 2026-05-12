#include "space_age.h"
#include <cmath>

namespace space_age {

	/*
		hat trailing const means:

		“This member function promises not to modify the object.”
	*/
	long long space_age::seconds() const {
		return age;
	}

	double space_age::on_earth() const {
		return static_cast<double>(age) / A_YEAR_EARTH_SECONDS;
	}

	double space_age::on_mercury() const {
		return on_earth() / MERCURY;
	}


	double space_age::on_venus() const {
		return on_earth() / VENUS;
	}


	double space_age::on_mars() const {
		return on_earth() / MARS;
	}


	double space_age::on_jupiter() const {
		return on_earth() / JUPITER;
	}


	double space_age::on_saturn() const {
		return on_earth() / SATURN;
	}


	double space_age::on_uranus() const {
		return on_earth() / URANUS;
	}


	double space_age::on_neptune() const {
		return on_earth() / NEPTUNE;
	}



	



}  // namespace space_age
