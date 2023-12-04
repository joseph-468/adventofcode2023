#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

int main() {
    std::ifstream file;
    std::string line;
    file.open("input.txt");

    int i;
    bool started;
    int num;
    int lineNum = 0;
    std::vector<std::unordered_set<int>> nums;
    while (getline(file, line)) {
        i = 0;
        started = false;
        nums.push_back({});
        while (line[i+1] != '|') {
            if (started) {
                num = 0;
                if (line[i+1] != ' ') {
                    num += (line[i+1]-48) * 10;
                }
                num += (line[i+2]-48);
                nums[lineNum].insert(num);
                i += 2;
            }
            if (line[i] == ':') {
               started = true; 
            } 
            i++;
        }
        lineNum++;
    }

    int sum;
    int result = 0;
    int winningNumsPos = i;
    file.clear();
    file.seekg(0);
    lineNum = 0;
    while (getline(file, line)) {
        sum = 0;
        i = winningNumsPos+2;
        while (i < line.length()) {
            num = 0;
            if (line[i+1] != ' ') {
                num += (line[i+1]-48) * 10;
            }
            num += (line[i+2]-48);
            if (nums[lineNum].count(num)) {
                if (sum == 0) sum = 1;
                else sum *= 2;
            }
            i += 3;
        }
        if (line[i] == ':') {
            started = true; 
        } 
        lineNum++;
        result += sum;
    }

    std::cout << result << std::endl;
}