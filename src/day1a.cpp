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
    int smallest = list[0];
    int index = 0;
    std::cout << smallest << std::endl;
    for (int i=1; i < list.size(); i++) {
        if (list[i] < smallest) {
            smallest = list.at(i);
            index = i;
        }
    }
    // std::cout << smallest << std::endl;
    return index;
}

int main() {
    const std::string DELIM = "   "; // For parsing the text file lines
    const int INT_MAX = std::numeric_limits<int>::max(); // Used for sillyness later :)
    auto lines = readlines("build/input/day1_test.txt");
    std::vector<int> col1, col2;

    for (int i=0; i < lines.size(); i++) {
        std::string line = lines.at(i);
        std::string col1num = line.substr(0, line.find(DELIM));
        std::string col2num = line.substr(line.find(DELIM), line.size());
        col1.push_back(stoi(col1num));
        col2.push_back(stoi(col2num));
    }

    // the is col1.size() pairs to check for.
    int distance_sum = 0;
    // std::cout << col1.size() << std::endl;
    for (int i=0; i < col1.size(); i++) {
        int col1_smallest_index = find_smallest(col1);
        int col2_smallest_index = find_smallest(col2);
        distance_sum += abs(col1_smallest_index - col2_smallest_index);
        // Change both numbers in the pair to the maximum integer so that they don't get double counted.
        col1[col1_smallest_index] = INT_MAX;
        // std::cout << col1.at(col1_smallest_index) << std::endl;
        col2[col2_smallest_index] = INT_MAX;
    }

    std::cout << distance_sum << std::endl;

    return 0;
}