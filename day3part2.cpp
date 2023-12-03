#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Pos {
    int x, y;
};

int main() {
    int result = 0;
    std::ifstream file;
    std::string line;
    std::vector<std::string> lines;
    file.open("input.txt");
    while (getline(file, line)) {
        lines.push_back(line);
    }

    for (int i = 0; i < lines.size(); i++) {
        for (int j = 0; j < lines[0].length(); j++) {
            if (lines[i][j] == '*') {
                std::vector<int> nums;
                std::vector<Pos> bad;
                int num;
                int end;
                int end2;
                int x;
                int len;
                for (int m = -1; m < 2; m++) {
                    len = 0;
                    num = 0;
                    end = j;
                    x = 1;
                    while (isdigit(lines[i+m][end])) {
                        len++;
                        end++;
                    }
                    while (isdigit(lines[i+m][--end])) {
                        num += (lines[i+m][end]-48) * x;
                        x *= 10;
                    }
                    bad.push_back({i+m, end});
                    if (num != 0) {
                        nums.push_back(num);
                    }
                }
                for (int m = -1; m < 2; m++) {
                    len = 0;
                    num = 0;
                    end = j+1;
                    x = 1;
                    while (isdigit(lines[i+m][end])) {
                        len++;
                        end++;
                    }
                    while (isdigit(lines[i+m][--end])) {
                        num += (lines[i+m][end]-48) * x;
                        x *= 10;
                    }
                    for (auto& pi : bad) {
                        if (i+m == pi.x && end == pi.y) num = 0;
                    }
                    if (num != 0) {
                        nums.push_back(num);
                    }
                }
                if (nums.size() == 2) result += nums[0] * nums[1];
            }
        }
    }
    std::cout << result;
}