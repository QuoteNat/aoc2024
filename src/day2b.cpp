#include <iostream>
#include <vector>
#include <string>
#include "helper.hpp"

int main() {
    std::vector<std::string> lines = readlines("input/day2_test.txt");
    
    int safe_reports = 0;
    for (int i=0; i < lines.size(); i++) {
        std::vector<int> report = parse_line<int>(lines[i], " ");
        bool safe = true;
        bool increasing = report[1] > report[0];
        bool tolerate = true;
        int j=0;
        while (j < report.size() - 1 && safe) { // we only check up to the 2nd to last element to prevent trying to check out of bounds
            int difference = abs(report[j+1] - report[j]);
            
            if (increasing != report[j+1] > report[j] || difference < 1 || difference > 3) {
                if (tolerate) {
                    tolerate = false;
                    // If j = 0, we just skip the first element. 
                    if (j > 0) {
                        int difference = abs(report[j+1] - report[j-1]);
                        if (increasing != report[j+1] > report[j-1] || difference < 1 || difference > 3) {
                            safe = false;
                        }
                    }
                    std:: cout << "Tolerate " << report[j] << " at index " << j << std::endl;
                } else {
                    safe = false;
                }
            }
            j++;
        }
        if (safe) std::cout << "Safe report index: " << i << std::endl;
        if (safe) safe_reports++;
    }
    std::cout << safe_reports << std::endl;
    return 0;
}