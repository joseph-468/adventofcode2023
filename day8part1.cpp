#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main() {
    int result = 0;

    std::fstream file("input.txt");
    std::string line;
    std::string instructions;
    std::vector<std::string> nodes; 

    getline(file, instructions);
    getline(file, line);
    while (getline(file, line)) {
        nodes.push_back(line);
    }

    int curNode;
    for (size_t i = 0; i < nodes.size(); i++) {
        if (nodes[i].substr(0, 3) == "AAA") {
            curNode = i;
        }
    }

    int cur = 0;
    while (true) {
        result++;
        if (instructions[cur] == 'L') {
            for (size_t i = 0; i < nodes.size(); i++) {
                if (nodes[i].substr(0, 3) == nodes[curNode].substr(7, 3)) {
                    curNode = i;
                    break;
                } 
            }
        }
        else {
            for (size_t i = 0; i < nodes.size(); i++) {
                if (nodes[i].substr(0, 3) == nodes[curNode].substr(12, 3)) {
                    curNode = i;
                    break;
                } 
            }
        }

        if (++cur == instructions.length()) {
            cur = 0;
        }

        if (nodes[curNode].substr(0, 3) == "ZZZ") break;
    }

    std::cout << "Result: " << result << std::endl;
}