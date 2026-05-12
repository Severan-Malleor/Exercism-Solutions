#pragma once


namespace space_age {

	class space_age {
		long long age{ 0 };



	public:
		space_age(long long seconds) : age(seconds){}

		long long seconds() const;
		double on_earth() const;
		double on_mercury() const;
		double on_venus() const;
		double on_mars() const;
		double on_jupiter() const;
		double on_saturn() const;
		double on_uranus() const;
		double on_neptune() const;

	private:
		// Orbital period in Earth Years
		const long long A_YEAR_EARTH_SECONDS = 31557600;
		const double MERCURY = 0.2408467;
		const double VENUS = 0.61519726;
		const double EARTH = 1.0;
		const double MARS = 1.8808158;
		const double JUPITER = 11.862615;
		const double SATURN = 29.447498;
		const double URANUS = 84.016846;
		const double NEPTUNE = 164.79132;

	};




}  // namespace space_age
