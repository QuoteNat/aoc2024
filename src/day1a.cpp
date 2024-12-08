#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <limits>

std::vector<std::string> readlines(std::string filepath) {
    std::string line;
    std::ifstream input(filepath);
    std::vector<std::string> lines;
    if (input.is_open()) {
        while (getline(input, line)) {
            lines.push_back(line);
        }
    }
    input.close();
    return lines;
}

int find_smallest(const std::vector<int>& list) {
    int smallest = list.front();
    for (int i=1; i < list.size(); i++) {
        if (list.at(i) < smallest) {
            smallest = list.at(i);
            std::cout << smallest << std::endl;
        }
    }
    return smallest;
}

int main() {
    const std::string DELIM = "   "; // For parsing the text file lines
    const int INT_MAX = std::numeric_limits<int>::max(); // Used for sillyness later :)
    auto lines = readlines("build/input/day1.txt");
    std::vector<int> col1, col2;

    for (int i=0; i<lines.size(); i++) {
        std::string line = lines.at(i);
        auto col1num = line.substr(0, line.find(DELIM));
        auto col2num = line.substr(line.find(DELIM), line.size());
        col1.push_back(stoi(col1num));
        col2.push_back(stoi(col2num));
    }


    std::cout << find_smallest(col1) << std::endl;
    return 0;
}