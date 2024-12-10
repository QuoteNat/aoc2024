#pragma once
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> readlines(std::string filepath);

template <typename T>
std::vector<T> parse_line(std::string line, std::string delim) {
    std::vector<int> indices;
    std::vector<T> parsed;
    int delim_length = delim.size();
    int found = 0;
    while (found < line.size()) {
        int find_index = line.find(delim, found+1);
        if (find_index != std::string::npos) {
            indices.push_back(find_index);
            found = find_index;
        } else {
            found = line.size();
            break;
        }
    }

    std::string element = line.substr(0, indices[0]);
    std::stringstream start_stream(element);
    T element_cast;
    start_stream >> element_cast;
    parsed.push_back(element_cast);
    for (int i=0; i < indices.size() - 1; i++) {
        std::string element = line.substr(indices[i] + 1, indices[i+1] - 1 - indices[i]);
        std::stringstream cast_stream(element);
        T element_cast;
        cast_stream >> element_cast;
        parsed.push_back(element_cast);
    }

    element = line.substr(indices.back(), line.size() - indices.back());
    std::stringstream end_stream(element);
    T last_cast;
    end_stream >> last_cast;
    parsed.push_back(last_cast);
    return parsed;
}