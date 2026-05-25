#pragma once
#include <string>
#include <unordered_set>
#include <vector>
#include <utility>

namespace allergies {

	class allergy_test {
	public:
		allergy_test(int);
		bool is_allergic_to(std::string);
		std::unordered_set<std::string> get_allergies();
	private:
		int score;

		std::vector<std::pair<std::string, int>> allergens = {
			{"eggs", 1},
			{"peanuts", 2},
			{"shellfish", 4},
			{"strawberries", 8},
			{"tomatoes", 16},
			{"chocolate", 32},
			{"pollen", 64},
			{"cats", 128},
		};

	};

}  // namespace allergies
