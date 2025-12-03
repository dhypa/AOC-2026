#include <vector>
#include <fstream>
#include <iostream>
#include <chrono>

void make_input_vector(const std::string &str, std::vector<int> &outVec);
std::vector<std::vector<int>>* parse_input();
int solution_part_1(const std::vector<std::vector<int>> &inputs);

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    auto* inputs = parse_input();
    auto solution = solution_part_1(*inputs);
    delete inputs;
    auto end = std::chrono::high_resolution_clock::now();
    long long us = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << solution << std::endl;
    std::cout << "Elapsed time: " << us << " uq\n";
    return 0;
}
/*
818181911912111
*/
int solution_part_1(const std::vector<std::vector<int>> &inputs){
    int total = 0;

    for(auto &num : inputs) {
        int first = num[num.size()-2];
        int second = num[num.size()-1];

        for(int i = num.size()-3; i >= 0; i--) {
            int current = num[i];
            if(current>=first) {
                int temp = first;
                if(temp > second) {
                    second = temp;
                }
                first = current;
            }
        }
        total += first * 10 + second;
    }
    return total;
}

std::vector<std::vector<int>>* parse_input() {
    std::ifstream input{"../3-Lobby/e.txt"};
    if (!input) {
        std::cerr << "Failed to open input file";
    }

    auto* inputs = new std::vector<std::vector<int>>;

    std::string line;
    while (std::getline(input, line)) {
        std::vector<int> inputVec;
        make_input_vector(line, inputVec);
        inputs->emplace_back(inputVec);
    }

    return inputs;
}

void make_input_vector(const std::string &str, std::vector<int> &outVec){
    for (int i = 0; i < str.size() - 1; ++i) {
        outVec.emplace_back(str[i] - '0');
    }
}
