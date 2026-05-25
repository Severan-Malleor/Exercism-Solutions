#include "kindergarten_garden.h"
#include <vector>
#include <utility>
#include <iostream>
#include <cctype>

namespace kindergarten_garden {

	std::array<kindergarten_garden::Plants, 4> plants(std::string plantRows, std::string owner) {

		std::array<kindergarten_garden::Plants, 4> ownerPlants{};
		std::string pots = "";

		std::vector<std::pair<std::string, int>> owners = {
			{"Alice", 0},
			{"Bob", 2},
			{"Charlie", 4},
			{"David", 6},
			{"Eve", 8},
			{"Fred", 10},
			{"Ginny", 12},
			{"Harriet", 14},
			{"Ileana", 16},
			{"Joseph", 18},
			{"Kincaid", 20},
			{"Larry", 22},
		};


		for (auto o : owners) {
			if (owner == o.first) {
				size_t secondRow = plantRows.find("\n") + 1;
				pots += plantRows.substr(o.second, 2);
				pots += plantRows.substr(secondRow + o.second, 2);

			}
		}

		for (size_t i = 0; i < pots.size(); ++i) {
			switch (pots[i]) {
			case 'G':
				ownerPlants[i] = kindergarten_garden::Plants::grass;
				break;
			case 'C':
				ownerPlants[i] = kindergarten_garden::Plants::clover;
				break;
			case 'R':
				ownerPlants[i] = kindergarten_garden::Plants::radishes;
				break;
			case 'V':
				ownerPlants[i] = kindergarten_garden::Plants::violets;
				break;
			} 
		}



		return ownerPlants;

	}

}  // namespace kindergarten_garden
