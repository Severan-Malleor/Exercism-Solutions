#include "perfect_numbers.h"
#include <stdexcept>
#include <cmath>
#include <iostream>

namespace perfect_numbers {

    classification classify(int num) {
        if (num <= 0) {
            throw std::domain_error("Number cannot be less than or equal to 0");
        } else if (num == 1) {
            return classification::deficient;
        }

        int root = static_cast<int>(std::sqrt(num));
        int aliquot = 1;

        for (int i = 2; i <= root; ++i) {
            if (num % i == 0) {
                int pair = num / i;

                aliquot = aliquot + i;

                if (pair != i) {
                    aliquot = aliquot + pair;
                }
            }
        }

        if (aliquot > num) return classification::abundant;
        else if (aliquot < num) return classification::deficient;
        else return classification::perfect;

        


    }

}  // namespace perfect_numbers
