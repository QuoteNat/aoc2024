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
    std::cout << "test! " << line << std::endl;
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

    std::cout << "Delims found: " << indices.size() << std::endl;

    std::string element = line.substr(0, indices[0]);
    std::cout << element << std::endl;
    std::stringstream cast_stream(element);
    T element_cast;
    cast_stream >> element_cast;
    parsed.push_back(element_cast);
    for (int i=0; i < indices.size(); i++) {
        std::string element = line.substr(indices[i] , indices[i+1] - indices[i]);
        std::stringstream cast_stream(element);
        T element_cast;
        cast_stream >> element_cast;
        parsed.push_back(element_cast);
    }

    return parsed;
}