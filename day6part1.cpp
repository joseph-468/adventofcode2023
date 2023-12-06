#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string times;
    std::string distances;

    std::fstream file("input.txt");
    getline(file, times);
    getline(file, distances);
    file.close();

    int result = 1;
    int x, time, record;
    for (int i = times.length()-1; i > 8; i -= 1) {
        if (isdigit(times[i]) || isdigit(distances[i])) {
            x = i;
            while (isdigit(times[i]) || isdigit(distances[i])) {
                i--;
            }
            time = stoi(times.substr(i, x)); 
            record = stoi(distances.substr(i, x));

            int combinations = 0;
            for (int i = 1; i < time; i++) {
                if ((time-i) * i > record) combinations++;
            }
            result *= combinations;
        }
    }

    std::cout << "Result: " << result << std::endl;
}