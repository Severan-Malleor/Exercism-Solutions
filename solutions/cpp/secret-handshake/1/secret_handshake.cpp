#include "secret_handshake.h"
#include <algorithm>

namespace secret_handshake {

	std::vector<std::string> commands(int num) {

		std::vector<std::string> secret{ };

		// For loop for bit position. we hardcode 5 since we are only working with 5 bits (0-4)
		for (int i = 0; i < 5; ++i) {
			
			// We shift the bit by 1 position to the left than AND to 
			if (num & (1 << i)) { 
				if (i == 0) {
					secret.emplace_back("wink");
				}
				else if (i == 1) {
					secret.emplace_back("double blink");
				}
				else if (i == 2) {
					secret.emplace_back("close your eyes");
				}
				else if (i == 3) {
					secret.emplace_back("jump");
				}
				else if (i == 4) {
					std::reverse(secret.begin(), secret.end());
				}
			}

		}





		return secret;
	}

}  // namespace secret_handshake
