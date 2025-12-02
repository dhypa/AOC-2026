#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>

std::vector<std::pair<long long, long long>> * parse_input();
long long solution_part_1(std::vector<std::pair<long long,long long>>& inputs);

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    auto *input = parse_input();
    long long solution = solution_part_1(*input);
    delete input;
    std::cout << "sol: " << solution << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Elapsed time: " << duration.count() << " ms\n";
    return 0;
}

long long solution_part_1(std::vector<std::pair<long long,long long>>& inputs){
    long long invalid = 0;
    for(const auto& pair : inputs) {
        for(auto num = pair.first; num <= pair.second; num++) {

            std::string str = std::to_string(num);
            if(str.length() % 2 == 1) continue;
            bool balanced = true;
            for(size_t i = 0; i < str.length() / 2; i++){
                if(str[i] != str[i + str.length()/2]) {
                    balanced = false;
                    break;
                }
            }
            if(balanced) {
                invalid += num;
            }
        }
    }
    return invalid;
}

std::vector<std::pair<long long, long long>> * parse_input() {
    std::ifstream input{"../2-GiftShop/e.txt"};
    if (!input) {
        std::cerr << "Failed to open input file";
    }

    auto *inputs  = new std::vector<std::pair<long long, long long>>;

    std::string str;
    input >> str;
    std::stringstream ss(str);
    std::string token;

    while(std::getline(ss, token, ',')) {
        std::size_t dashPos = token.find('-');
        if(dashPos != std::string::npos) {
            u_long start = std::stol(token.substr(0, dashPos));
            u_long end = std::stol(token.substr(dashPos+1));

            inputs->emplace_back(start, end);
        }
    }

    return inputs;
}