#include "lasagna_master.h"
#include <vector>
#include <string>

namespace lasagna_master {

	int preparationTime(std::vector<std::string> layers, int average_prep_time) {
		return static_cast<int>(layers.size()) * average_prep_time;
	}


	amount quantities(std::vector<std::string> layers) {
		int noodles_needed{ 0 };
		double sauce_needed{ 0.0 };

		for (int i{ 0 }; i < layers.size(); ++i) {
			if (layers[i] == "noodles") {
				noodles_needed += 50;
			}
			else if (layers[i] == "sauce") {
				sauce_needed += 0.2;
			}
		}

		return amount{ noodles_needed, sauce_needed };
	}


	void addSecretIngredient(std::vector<std::string>& mylist, std::vector<std::string> friendsList) {
		std::string friends_list_last_item = friendsList[friendsList.size() - 1];
		mylist.at(mylist.size() - 1) = friends_list_last_item;
	}

	std::vector<std::string> addSecretIngredient(std::vector<std::string>& myList, std::string secretIngredient) {
		myList.at(myList.size() - 1) = secretIngredient;

		return myList;
	}

	std::vector<double> scaleRecipe(std::vector<double> quantities, int portions) {

		if (quantities.empty()) {
			return quantities;
		}

		std::vector<double> scaled{};

		for (int i{ 0 }; i < quantities.size(); ++i) {
			scaled.emplace_back(quantities[i] * (portions / 2.0));
		}

		return scaled;
	}



}  // namespace lasagna_master
