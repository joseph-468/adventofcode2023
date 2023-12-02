#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int main() {
    // Worst code i've wrote in a while
    std::ifstream file("input.txt");
    std::string line;
    int id = 0;
    int result = 0;
    while (getline(file, line)) {
        id++;
        int mr, mg, mb;
        mr = mg = mb = 0;
        int r, g, b; 
        int x, j;
        for (int i = 0; i < line.length(); i++) {
            j = i;
            if (line[j] == ';' || j == line.length()-1) {
                if (mr > 12 || mg > 13 || mb > 14) {
                    break;
                }
                mr = mg = mb = 0;
            }
            else if (line[j] == 'r') {
                r = 0;
                x = 1;
                j--;
                while (isdigit(line[--j])) {
                    r += (line[j]-48) * x;
                    x *= 10;
                }
                if (r > mr) mr = r;
            } 
            else if (line[j] == 'g') {
                g = 0;
                x = 1;
                j--;
                while (isdigit(line[--j])) {
                    g += (line[j]-48) * x;
                    x *= 10;
                }
                if (g > mg) mg = g;
            } 
            else if (line[j] == 'b') {
                b = 0;
                x = 1;
                j--;
                while (isdigit(line[--j])) {
                    b += (line[j]-48) * x;
                    x *= 10;
                }
                if (b > mb) mb = b;
            } 
            if (i == line.length()-1) result += id;
        }
    }
    std::cout << result;
}