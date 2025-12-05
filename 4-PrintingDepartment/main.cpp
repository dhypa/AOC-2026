#include <vector>
#include <fstream>
#include <iostream>
#include <chrono>
#include <array>

void make_input_vector(const std::string &str, std::vector<bool> &outVec);

std::vector<std::vector<bool>> *parse_input();

bool withinBounds(int i, int j, const std::vector<std::vector<bool>> &arr);

int solution_part_1(const std::vector<std::vector<bool>> &inputs);

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    auto *inputs = parse_input();
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
int solution_part_1(const std::vector<std::vector<bool>> &inputs) {
    std::array<std::pair<int, int>, 8> directions{
            std::pair<int, int>{-1, 1},
            std::pair<int, int>{-1, 0},
            std::pair<int, int>{-1, -1},
            std::pair<int, int>{1, -1},
            std::pair<int, int>{1, 0},
            std::pair<int, int>{1, 1},
            std::pair<int, int>{0, 1},
            std::pair<int, int>{0, -1}

//   //   //
//        //
//   //   //
    };

    int rolls{0};
    for (int i = 0; i < inputs.size(); i++) {
        const auto &line = inputs[i];
        for (int j = 0; j < line.size(); j++) {
            const auto &ch = line[j];
            if (!ch) {
                continue;
            }
            int count{0};

            for (const auto &direction: directions) {
                int x = i + direction.first;
                int y = j + direction.second;
                if (withinBounds(x, y, inputs) && inputs[x][y] == true) {
                    count++;
                }
            }
            if (count < 4)
                rolls++;
        }
    }
    return rolls;
}

bool withinBounds(int i, int j, const std::vector<std::vector<bool>> &arr) {
    return (arr.size() > i > 0) && (arr[0].size() > j > 0);
}

std::vector<std::vector<bool>> *parse_input() {s
    std::ifstream input{"../4-PrintingDepartment/e.txt"};
    if (!input) {
        std::cerr << "Failed to open input file";
    }

    auto *inputs = new std::vector<std::vector<bool>>;

    std::string line;
    while (std::getline(input, line)) {
        std::vector<bool> inputVec;
        make_input_vector(line, inputVec);
        inputs->emplace_back(inputVec);
    }

    return inputs;
}

void make_input_vector(const std::string &str, std::vector<bool> &outVec) {
    for (int i = 0; i < str.size() - 1; ++i) {
        outVec.emplace_back(str[i] != '.');
    }
}
