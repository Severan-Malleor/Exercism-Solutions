#include "sum_of_multiples.h"
#include <set>
#include <iostream>
namespace sum_of_multiples {

	int to(std::vector<int> items, int level) {

		int sum = 0;

		if (items.empty() || level == 0) {
			return 0;
		}
		
		// Set keeps things sorted
		std::set<int> multiples{};

		for (auto item : items) {
			if (item == 0) {
				continue;
			}
			for (int i = 1; item * i < level; ++i) {
				multiples.insert(item * i);
			}
		}

		for (int m : multiples) {
			sum += m;
		}

		return sum;
	}

}  // namespace sum_of_multiples
