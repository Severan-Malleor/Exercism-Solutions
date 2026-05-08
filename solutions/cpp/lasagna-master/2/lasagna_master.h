#pragma once
#include <string>
#include <vector>

namespace lasagna_master {

    struct amount {
        int noodles;
        double sauce;
    };

    int preparationTime(std::vector<std::string>, int average_prep_time = 2);

    amount quantities(std::vector<std::string>);

    void addSecretIngredient(std::vector<std::string>&, std::vector<std::string>);

    std::vector<double> scaleRecipe(std::vector<double>, int);

    std::vector<std::string> addSecretIngredient(std::vector<std::string>&, std::string);

}  // namespace lasagna_master
