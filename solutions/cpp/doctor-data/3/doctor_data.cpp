#include "doctor_data.h"
#include <string>

namespace heaven {

	Vessel::Vessel(std::string name, int generation, star_map::System system)
		: name{name}, generation{generation}, current_system{system} {}

	Vessel Vessel::replicate(std::string replicate_name) {
		return Vessel{ replicate_name, ++generation, current_system };
	}

	void Vessel::make_buster() {
		busters += 1;
	}

	bool Vessel::shoot_buster() {
		if (busters > 0) {
			busters -= 1;
			return true;
		}
		else { 
			return false; 
		}
	}

	std::string get_older_bob(Vessel a, Vessel b) {

		// If the generation is the higher number, than its newer. gen 2 > gen 1. Gen 1 is older.
		if (a.generation > b.generation) {
			return b.name;
		}
		else {
			return a.name;
		}
	}

	bool in_the_same_system(Vessel a, Vessel b) {
		if (a.current_system == b.current_system) {
			return true;
		}
		else {
			return false;
		}
	}


}