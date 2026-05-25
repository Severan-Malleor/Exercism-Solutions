#include "allergies.h"

namespace allergies {

	allergy_test::allergy_test(int s) : score(s) {}

	bool allergy_test::is_allergic_to(std::string str) {

		for (auto a : allergens) {
			if (a.first == str) {
				return score & a.second;
			}
		}

		return true;


	}

	std::unordered_set<std::string> allergy_test::get_allergies() {
		
		std::unordered_set<std::string> allergies;

		for (auto a : allergens) {
			if (score & a.second) {
				allergies.emplace(a.first);
			}
		}

		return allergies;


	}




}  // namespace allergies
