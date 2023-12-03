#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    int result = 0;
    std::ifstream file;
    std::string line;
    std::vector<std::string> lines;
    file.open("input.txt");
    while (getline(file, line)) {
        lines.push_back(line);
    }
    std::vector<std::vector<bool>> valid(lines.size(), std::vector<bool>(line.length()));

    for (int i = 0; i < lines.size(); i++) {
        for (int j = 0; j < lines[0].length(); j++) {
            if (lines[i][j] != '.' && !isdigit(lines[i][j])) {
                valid[i][j-1] = true;
                valid[i][j+1] = true;
                valid[i-1][j] = true;
                valid[i+1][j] = true;
                valid[i-1][j+1] = true;
                valid[i+1][j+1] = true;
                valid[i-1][j-1] = true;
                valid[i+1][j-1] = true;
            }
        }
    }

    for (int i = 0; i < lines.size(); i++) {
        for (int j = 0; j < lines[0].length(); j++) {
            if (isdigit(lines[i][j])) {
                bool validNum = false;
                if (valid[i][j] == true) validNum = true;
                int start = j;
                int end = j;
                while (isdigit(lines[i][++j]) && j < lines[0].length()) {
                    if (valid[i][j] == true) validNum = true;
                    end = j; 
                }
                if (validNum) {
                    int num = 0;
                    int x = 1;
                    while (isdigit(lines[i][end])) {
                        num += (lines[i][end]-48) * x; 
                        x *= 10;
                        end--;
                    }
                    result += num;
                }
            }
        }
    }
    std::cout << result << std::endl;
}