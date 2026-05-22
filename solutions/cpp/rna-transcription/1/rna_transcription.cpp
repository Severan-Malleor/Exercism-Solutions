#include "rna_transcription.h"


namespace rna_transcription {


	// Overloading.

	std::string to_rna(std::string protein) {
		unsigned int proteinSize = static_cast<unsigned int>(protein.size());

		std::string newProtein{ "" };

		for (auto c : protein) {
			switch (c) {
			case 'G':
				newProtein += 'C';
				continue;
			case 'C':
				newProtein += 'G';
				continue;
			case 'T':
				newProtein += 'A';
				continue;
			case 'A':
				newProtein += 'U';
				continue;
			}
		}

		return newProtein;

	}

	char to_rna(char protein) {
		
		switch (protein) {
		case 'G':
			return 'C';
		case 'C':
			return 'G';
		case 'T':
			return 'A';
		case 'A':
			return 'U';
		default:
			return 'Z';
		}
	}

}  // namespace rna_transcription
