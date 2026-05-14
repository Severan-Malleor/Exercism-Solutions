#include "protein_translation.h"
#include <map>



namespace protein_translation {

    static const std::map<std::string, std::string> proteinMap {
                    {"AUG", "Methionine"},
                    {"UUU", "Phenylalanine"},
                    {"UUC", "Phenylalanine"},
                    {"UUA", "Leucine"},
                    {"UUG", "Leucine"},
                    {"UCU","Serine"},
                    {"UCC","Serine"},
                    {"UCA","Serine"},
                    {"UCG","Serine"},
                    {"UAU", "Tyrosine"},
                    {"UAC", "Tyrosine"},
                    {"UGU", "Cysteine"},
                    {"UGC", "Cysteine"},
                    {"UGG", "Tryptophan"},
                    {"UAA", "STOP"},
                    {"UAG", "STOP"},
                    {"UGA", "STOP"},
                };

    std::vector<std::string> proteins(std::string proteinString) {

        if (proteinString.empty()) {
            return {};
        }

        int proteinStringSize = static_cast<int>(proteinString.size());

        if (proteinStringSize % 3 == 0) {
            std::vector<std::string> proteins;
            for (int i{0}; i < proteinStringSize; i += 3) {
                std::string extractedCodon = proteinString.substr(i, 3);
                std::string protein = proteinMap.at(extractedCodon);
                if (protein == "STOP") {
                    return proteins;
                } else {
                    proteins.emplace_back(protein);
                }
            }
            return proteins;
        } else {
            return {};
        }
    }

}  // namespace protein_translation
