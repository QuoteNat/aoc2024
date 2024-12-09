#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <map>
#include "helper.hpp"

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

// this sorts in ascending order, however we'll be using pop_back to start with the smallest numbers
bool tuple_sort(std::tuple<int, int> a, std::tuple<int, int> b) {
    if (std::get<0>(a) == std::get<0>(b)) {
        return std::get<1>(a) < std::get<1>(b);
    } else {
        return std::get<0>(a) > std::get<0>(b);
    }
}

int main() {
    const std::string DELIM = "   "; // For parsing the text file lines
    auto lines = readlines("build/input/day1.txt");
    std::vector<int> col1, col2;
    std::map<int, int> occurence_map;

    for (int i=0; i < lines.size(); i++) {
        std::string line = lines.at(i);
        int col1num = stoi(line.substr(0, line.find(DELIM)));
        int col2num = stoi(line.substr(line.find(DELIM), line.size()));
        // store the index to calculate distance later
        col1.push_back(col1num);
        col2.push_back(col2num);
    }

    // std::sort(col1.begin(), col1.end(), tuple_sort);
    // std::sort(col2.begin(), col2.end(), tuple_sort);

    for (int i=0; i < col2.size(); i++) {
        if (occurence_map.find(col2[i]) != occurence_map.end()) {
            occurence_map[col2[i]] += 1;
        } else {
            occurence_map.insert({col2[i], 1});
        }
    }

    // the is col1.size() pairs to check for.
    int similarity_sum = 0;
    for (int i=0; i < col1.size(); i++) {
        if (occurence_map.find(col1[i]) != occurence_map.end()) {
            similarity_sum += col1[i] * occurence_map[col1[i]];
        }
    }

    std::cout << similarity_sum << std::endl;

    return 0;
}