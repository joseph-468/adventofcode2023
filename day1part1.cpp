#include <iostream>
#include <fstream>
#include <string>

int main() {
    int sum = 0;
    std::ifstream file;
    std::string line;
    file.open("input.txt");
    while (getline(file, line)) {
        char num[2] = {'\0', '\0'};
        for (int i = 0; i < line.length(); i++) {
            if (isdigit(line[i]) && !num[0]) {
                num[0] = line[i];
                num[1] = line[i];
            }
            else if (isdigit(line[i])) {
                num[1] = line[i];
            }
        }
        sum += (num[0]-48) * 10 + (num[1]-48);
    }
    file.close();
    std::cout << sum << std::endl;
}