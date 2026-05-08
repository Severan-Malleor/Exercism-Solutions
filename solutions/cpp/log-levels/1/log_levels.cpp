#include <string>

namespace log_line {
    std::string message(std::string line) {
        int startAt = line.find(" ") + 1;

        return line.substr(startAt);

    }

    std::string log_level(std::string line) {

        int startAt = line.find("[") + 1 ;
        int stopAt = line.find("]") - 1 ;

        return line.substr(startAt, stopAt);
    }

    std::string reformat(std::string line) {
        return message(line) + " " + "(" + log_level(line) + ")";
    }
}
