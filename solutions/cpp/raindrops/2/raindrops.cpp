#include "raindrops.h"
#include <string>

namespace raindrops {

	std::string convert(int num) {

		std::string raindrop{ "" };

		if (num % 3 == 0) {
			raindrop = raindrop + "Pling";
		}

		if (num % 5 == 0) {
			raindrop = raindrop + "Plang";
		}

		if (num % 7 == 0) {
			raindrop = raindrop + "Plong";
		}

		if (raindrop == "") {
			return std::to_string(num);
		}
		else {
			return raindrop;
		}

	}



}  // namespace raindrops