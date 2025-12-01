#include <iostream>
#include <fstream>
#include <vector>

using Rotation = std::pair<char, int>;

std::vector<Rotation> *parse_input();
int solve(std::vector<Rotation> &inputs);

int main() {
    auto *input = parse_input();

    int solution = solve(*input);

    std::cout << solution;
    return 0;
}

int solve(std::vector<Rotation> &inputs) {
    int counter = 0;
    int pointer = 50;
    for (int i = 0; i < inputs.size(); ++i) {
        Rotation r = inputs[i];
        if (r.first == 'L') {
            pointer = (pointer - r.second) % 100;
            if (pointer < 0) {
                pointer += 100;
            }
        } else {
            pointer = (pointer + r.second) % 100;
        }
        if (pointer == 0) {
            counter++;
        }
    }
    return counter;
}

std::vector<Rotation> *parse_input() {
    std::ifstream input{"../1-SecretEntrance/e.txt"};
    if (!input) {
        std::cerr << "Failed to open input file";
    }

    auto *rotations = new std::vector<Rotation>;
    rotations->reserve(4035);

    std::string str;
    while (input >> str) {
        auto e = str[0];
        auto n = std::stoi(str.substr(1));
        rotations->push_back({str[0], std::stoi(str.substr(1))});
    }
    return rotations;
}
