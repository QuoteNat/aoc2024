#include <vector>
#include <memory>
#include <algorithm>
#include "helper.hpp"

// std::vector<std::string> readlines(std::string filepath) {
//     std::string line;
//     std::ifstream input(filepath);
//     std::vector<std::string> lines;
//     if (input.is_open()) {
//         while (getline(input, line)) {
//             lines.push_back(line);
//         }
//     }
//     input.close();
//     return lines;
// }

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
    std::vector<std::tuple<int, int>> col1, col2;

    for (int i=0; i < lines.size(); i++) {
        std::string line = lines.at(i);
        int col1num = stoi(line.substr(0, line.find(DELIM)));
        int col2num = stoi(line.substr(line.find(DELIM), line.size()));
        // store the index to calculate distance later
        col1.push_back({col1num, i});
        col2.push_back({col2num, i});
    }

    std::sort(col1.begin(), col1.end(), tuple_sort);
    std::sort(col2.begin(), col2.end(), tuple_sort);

    // the is col1.size() pairs to check for.
    int distance_sum = 0;
    for (int i=0; i < lines.size(); i++) {
        std::tuple<int, int> pair1 = col1.back();
        std::tuple<int, int> pair2 = col2.back();
        distance_sum += abs(std::get<0>(pair1) - std::get<0>(pair2));
        col1.pop_back();
        col2.pop_back();
    }

    std::cout << distance_sum << std::endl;

    return 0;
}