#include "atbash_cipher.h"
#include <cctype>


// Second option without lookups. Used https://www.alpharithms.com/ascii-table-512119/ for ASCII map to further understand ASCII math.

namespace atbash_cipher {

	std::string encode(std::string plainText) {

		std::string encodedText{ "" };

		for (int i{ 0 }; i < static_cast<int>(plainText.size()); ++i) {

			char ch = std::tolower(plainText[i]);

			if (std::isspace(ch) || std::ispunct(ch)) {
				continue;
			}

			if (encodedText.size() > 0 && encodedText.size() % 6 == 5) {
				encodedText += " ";
			}

			if (ch >= '0' && ch <= '9') {
				encodedText += ch;
			} else {
				encodedText += 'z' - (ch - 'a');
			}
		}

		return encodedText;
	}

	std::string decode(std::string encodedText) {
		
		std::string plainText{ "" };

		for (int i{ 0 }; i < static_cast<int>(encodedText.size()); ++i) {
			char ch = std::tolower(encodedText[i]);

			if (std::isspace(ch) || std::ispunct(ch)) {
				continue;
			}

			if (ch >= '0' && ch <= '9') {
				plainText += ch;
			}
			else {
				plainText += 'a' + ('z' - ch);
			}
		}

		return plainText;
	}

}  // namespace atbash_cipher
