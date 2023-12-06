#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main() {
    std::string times;
    std::string distances;

    std::fstream file("input.txt");
    getline(file, times);
    getline(file, distances);
    file.close();

    int result = 0;
    long long time = 0;
    long long record = 0;

    long long x = 1;
    long long y = 1;
    for (int i = distances.length()-1; i > 8; i--) {
        if (isdigit(times[i])) {
            time += (times[i]-48) * x;
            x *= 10;
        }
        if (isdigit(distances[i])) {
            record += (distances[i]-48) * y;
            y *= 10;
        }
    }

    for (int i = 1; i < time; i++) {
        if ((time-i) * i > record) result++;
    }

    std::cout << "Result: " << result << std::endl;
}