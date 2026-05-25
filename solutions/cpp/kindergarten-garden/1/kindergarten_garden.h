#pragma once
#include <string>
#include <array>

namespace kindergarten_garden {

	enum class Plants {
		clover,
		grass,
		violets,
		radishes
	};

	std::array<kindergarten_garden::Plants, 4> plants(std::string, std::string);

}  // namespace kindergarten_garden
