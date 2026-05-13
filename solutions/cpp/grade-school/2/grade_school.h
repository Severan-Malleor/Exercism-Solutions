#pragma once
#include <map>
#include <string>
#include <vector>

namespace grade_school {

	class school {
	public:
		std::map<int, std::vector<std::string>> roster() const;
		void add(std::string, int);
		std::vector<std::string> grade(int) const;
	private:
		std::map<int, std::vector<std::string>> students;

	};

}  // namespace grade_school
