#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
const std::string DELIM = "   ";

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
    std::cout << lines.size() << std::endl;
    return lines;
}

int main() {
    auto lines = readlines("build/input/day1.txt");
    std::vector<int> col1, col2;

    for (int i=0; i<lines.size(); i++) {
        std::string line = lines.at(i);
        auto col1num = line.substr(0, line.find(DELIM));
        auto col2num = line.substr(line.find(DELIM), line.size());
        col1.push_back(stoi(col1num));
        col2.push_back(stoi(col2num));
    }


    return 0;
}