#include "trinary.h"
#include <string>
#include <cmath>

namespace trinary {

    int to_decimal(std::string num_string) {

        int decimal{ 0 };
        int power_position = num_string.length() - 1;

        for (int i{ 0 }; i < num_string.length(); ++i) {
            char ch = num_string[i];
            int digit{ 0 };

            if (ch == '0') {
                digit = 0;
            }
            else if (ch == '1') {
                digit = 1;
            }
            else if (ch == '2') {
                digit = 2;
            }
            else {
                return 0;
            }

            decimal += digit * std::pow(3, power_position);
            power_position--;


        }

        return decimal;
    }

}  // namespace trinary