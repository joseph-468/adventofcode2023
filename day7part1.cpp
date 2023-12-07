#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <array>
#include <unordered_map>

std::unordered_map<char, int> conversion = {
    {'2', 1},
    {'3', 2},
    {'4', 3},
    {'5', 4},
    {'6', 5},
    {'7', 6},
    {'8', 7},
    {'9', 8},
    {'T', 9},
    {'J', 10},
    {'Q', 11},
    {'K', 12},
    {'A', 13},
};

int getType(const std::string& card) {
    bool two = false;
    std::array<int, 14> occurences = {0};
    for (int i = 0; i < 5; i++) {
        occurences[conversion[card[i]]] += 1;
    }
    for (auto& i : occurences) {
        if (i == 5) return 0;
        else if (i == 4) return 1; 
        else if (i == 3) {
            for (auto& j : occurences) {
                if (j == 2) return 2; 
                else if (j == 1) return 3; 
            }
        }
        else if (two && i == 2) return 4; 
        if (i == 2) {
            two = true;
        }
    }
    if (two) return 5; 
    else return 6; 
}

int main() {
    std::array<std::vector<std::string>, 7> cards;
    bool inserted;
    int type;

    std::fstream file("input.txt");
    std::string line;

    while (getline(file, line)) {
        inserted = false;
        type = getType(line);
        for (int i = 0; i < cards[type].size(); i++) {
            for (int j = 0; j < 5; j++) {
                if (conversion[line[j]] > conversion[cards[type][i][j]]) {
                    cards[type].insert(cards[type].begin()+i, line);
                    inserted = true;
                    break;
                }
                else if (conversion[line[j]] < conversion[cards[type][i][j]]) break;
            }
            if (inserted) break;
        }
        if (!inserted) {
            cards[getType(line)].push_back(line);
        }
    }

    int result = 0; 
    int rank = 1;
    for (int i = 6; i > -1; i--) {
        for (int j = cards[i].size()-1; j > -1; j--) {
            result += stoi(cards[i][j].substr(6)) * rank;
            rank++;
        }
    }

    std::cout << "Result: " << result << std::endl;
}