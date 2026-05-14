#include "atbash_cipher.h"

#include <cctype>

namespace atbash_cipher {

	std::string getAlphabet() {
		std::string alphabet{ "" };

		// Create alphabet 
		char c = 'a';
		for (int i{ 0 }; i < 26; ++i) {
			alphabet += c;
			c++;
		}

		return alphabet;
	}

	std::string getReversed() {
		std::string alphabet = getAlphabet();
		std::string reversed(alphabet.rbegin(), alphabet.rend());

		return reversed;
	}

	std::string encode(std::string plainText) {

		std::string encodedText{ "" };
		std::string alphabet = getAlphabet();
		std::string reversed = getReversed();

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
				auto charIndex = alphabet.find(ch);
				/*
					find() returns std::string::npos if the character is not found. Since we already filtered punctuation/spaces, 
					it probably works for Exercism inputs, but safer code would check it:				
				*/
				if (charIndex != std::string::npos) {
					encodedText += reversed[charIndex];
				}
			}
		}

		return encodedText;
	}

	std::string decode(std::string encodedText) {
		
		std::string plainText{ "" };
		std::string alphabet = getAlphabet();
		std::string reversed = getReversed();

		for (int i{ 0 }; i < static_cast<int>(encodedText.size()); ++i) {
			char ch = std::tolower(encodedText[i]);

			if (std::isspace(ch) || std::ispunct(ch)) {
				continue;
			}

			if (ch >= '0' && ch <= '9') {
				plainText += ch;
			}
			else {
				auto charIndex = reversed.find(ch);
				if (charIndex != std::string::npos) {
					plainText += alphabet[charIndex];
				}
			}
		}

		return plainText;
	}

}  // namespace atbash_cipher
