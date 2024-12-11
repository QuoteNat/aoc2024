#include <iostream>
#include <regex>

#include "helper.hpp"

int main() {
    std::vector<std::string> lines = readlines("input/day3_test.txt");
    std::regex mul_regex("mul\\(\\d{1,3},\\d{1,3}\\)");
    std::cout << lines.size() << std::endl;
    for (int i=0; i < lines.size(); i++) {
        auto line = lines[i];
        std::cout << line << std::endl;
        auto op_begin = std::sregex_iterator(line.begin(), line.end(), mul_regex);
        auto op_end = std::sregex_iterator();

        std::cout << "Found " << std::distance(op_begin, op_end) << " ops.\n";
        for (std::regex_iterator i = op_begin; i != op_end; i++) {
            
        }
    }

    return 0;
}