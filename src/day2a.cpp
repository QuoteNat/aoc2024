#include <iostream>
#include <vector>
#include <string>
#include "helper.hpp"

int main() {
    std::vector<std::string> lines = readlines("input/day2_test.txt");
    std::vector<int> parsed_test = parse_line<int>(lines[0], " ");
    for (int i=0; i < parsed_test.size(); i++) {
        std::cout << parsed_test[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}