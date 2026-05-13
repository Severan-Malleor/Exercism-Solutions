#include "grade_school.h"
#include <stdexcept>
#include <algorithm>

namespace grade_school {


	//Because this ordering is a fundamental part of the container's structure (typically a Red-Black Tree), you cannot use std::sort() on a map.
	std::map<int, std::vector<std::string>> school::roster() const {
		return students;
	}

	void school::add(std::string name, int grade) {

		/*
			Instead of push_back, .add() uses lower_bound to insert each name in sorted position. This means:
			* roster() already returns sorted vectors
			* grade() still works correctly.

		*/
		auto& vec = students[grade];

		// Here we can add the value according the grade key. This allows us to keep things sorted.
		vec.insert(std::lower_bound(vec.begin(), vec.end(), name), name);
	}

	std::vector<std::string> school::grade(int grade) const {
		try {
			return students.at(grade);
		}
		catch (const std::out_of_range&) {
			return {};
		}
	}


}  // namespace grade_school
