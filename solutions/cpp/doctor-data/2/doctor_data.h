#pragma once
#include <string>

namespace star_map {
	enum class System {
		BetaHydri,
		EpsilonEridani,
		AlphaCentauri,
		DeltaEridani,
		Omicron2Eridani,
		Sol
	};
}

namespace heaven {

	class Vessel {
	public:
		std::string name{};
		int generation{};
		star_map::System current_system{};
		int busters{ 0 };

		Vessel(std::string name, int generation, star_map::System system = star_map::System::Sol);
		Vessel replicate(std::string replicate_name);
		void make_buster();
		bool shoot_buster();
	};

	std::string get_older_bob(Vessel a, Vessel b);
	bool in_the_same_system(Vessel a, Vessel b);
}