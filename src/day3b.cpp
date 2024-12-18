#include <iostream>
#include <regex>

#include "helper.hpp"

int main() {
    std::vector<std::string> lines = readlines("input/day3.txt");
    std::regex mul_regex("mul\\(\\d{1,3},\\d{1,3}\\)|do\\(\\)|don't\\(\\)");

    int sum = 0;
    bool do_ops = true;
    for (int i=0; i < lines.size(); i++) {
        auto line = lines[i];
        auto op_begin = std::sregex_iterator(line.begin(), line.end(), mul_regex);
        auto op_end = std::sregex_iterator();

        for (std::regex_iterator i = op_begin; i != op_end; i++) {
            auto match = i->str();
            if (match == "do()") {
                do_ops = true;
            } else if (match == "don't()") {
                do_ops = false;
            } else if (do_ops) {
                int product = 1;
                std::regex num("\\d{1,3}");
                auto mul_begin = std::sregex_iterator(match.begin(), match.end(), num);
                auto mul_end = std::sregex_iterator();
                for (std::regex_iterator i = mul_begin; i != mul_end; i++) {
                    product *= stoi(i->str());
                }
                sum += product;
            }
        }
    }

    std::cout << sum << std::endl;
    return 0;
}