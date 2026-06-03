#include "resistor_color_duo.h"


namespace resistor_color_duo {

    int value(std::vector<std::string> colors) {

        if (colors.size() <= 1) return 0;

        int resistorValue = 0;

        std::string colorValues[10] = {
            "black",
            "brown",
            "red",
            "orange",
            "yellow",
            "green",
            "blue",
            "violet",
            "grey",
            "white",
        };

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (colors[i] == colorValues[j]){
                    resistorValue = resistorValue * 10 + j;
                }
            }
        }

        return resistorValue;

    }

}  // namespace resistor_color_duo
