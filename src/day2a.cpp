#include <iostream>
#include <vector>
#include <string>
#include "helper.hpp"

int main() {
    std::vector<std::string> lines = readlines("input/day2.txt");
    
    int safe_reports = 0;
    for (int i=0; i < lines.size(); i++) {
        std::vector<int> report = parse_line<int>(lines[i], " ");
        bool safe = true;
        bool increasing = report[1] > report[0];
        int j=0;
        while (j < report.size() - 1 && safe) { // we only check up to the 2nd to last element to prevent trying to check out of bounds
            int difference = abs(report[j+1] - report[j]);
            
            if (increasing != report[j+1] > report[j] || difference < 1 || difference > 3) {
                safe = false;
            }
            j++;
        }
        if (safe) safe_reports++;
    }
    std::cout << safe_reports << std::endl;
    return 0;
}