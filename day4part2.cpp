#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

int main() {
    std::ifstream file;
    std::string line;
    file.open("input.txt");

    int result = 0;

    int i;
    bool started;
    int num;
    int lineNum = 0;
    std::vector<int> cards;
    std::vector<std::unordered_set<int>> nums;
    std::vector<int> matches;

    while (getline(file, line)) {
        cards.push_back(1);
        result++;
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

    int winningNumsPos = i;
    int m;
    file.clear();
    file.seekg(0);
    lineNum = 0;
    while (getline(file, line)) {
        m = 0;
        i = winningNumsPos+2;
        while (i < line.length()) {
            num = 0;
            if (line[i+1] != ' ') {
                num += (line[i+1]-48) * 10;
            }
            num += (line[i+2]-48);
            if (nums[lineNum].count(num)) {
                m++;
            }
            i += 3;
        }
        lineNum++;
        matches.push_back(m);
    }
    result  = 0;
    
    bool cardsLeft = true;
    while (cardsLeft) {
        cardsLeft = false;
        for (int i = 0; i < cards.size(); i++) {
            if (cards[i] != 0) {
                cardsLeft = true;
                result++;
                cards[i] -= 1;
                for (int j = 1; j < matches[i]+1; j++) {
                    cards[i+j]++;
                }
            }
        }
    }

    std::cout << result << std::endl;
}