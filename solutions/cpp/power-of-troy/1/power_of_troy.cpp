#include "power_of_troy.h"

namespace troy {

	void give_new_artifact(human& human, std::string artifact_name) {
		human.possession = std::make_unique<artifact>(artifact_name);
	}

	void exchange_artifacts(std::unique_ptr<artifact>& artifact_one, std::unique_ptr<artifact>& artifact_two) {

		// Best way to think about this. Unique artifacts does not care which human it belongs to. Hence we can swap artifacts between humans while keeping the
		// artifact object completely unique. Like swapping playing cards.

		/*
			1. Using std::swap (Standard Method). The most common way to swap variables is by using std::swap from the <utility> header (Mayber. S
			(or <algorithm> in older standards)

			Efficiency: For Standard Template Library (STL) containers like std::vector or std::string, std::swap is extremely fast O(1)
			because it swaps internal pointers rather than copying every element.

			Safety: It works with almost any data type, including objects and arrays.
		*/
		std::swap(artifact_one, artifact_two);
	}

	void manifest_power(human& human, std::string special_power) {
		human.own_power = std::make_shared<power>(special_power);
	}

	void use_power(human& caster, human& target) {
		target.influenced_by = caster.own_power;
	}


	int power_intensity(human& caster) {


		// The use_count() function returns a long representing the number of shared pointers pointing to the same resource.
		// That way we can keep track of how many people the caster has casted on.

		// Think of it like this, we can keep track of a spell being casted on people by this caster and subtract 1 if not casted on own self, or keep it as is
		// if the spell also effects the caster. 
		auto intensity = caster.own_power.use_count();

		if (intensity <= 0) {
			return 0;
		}
		else {
			return intensity;
		}
	}

}  // namespace troy
