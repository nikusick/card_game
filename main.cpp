#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>


int main(int argc, char** argv) {
    if (argc == 3) {
        std::ifstream fin(argv[1]);
        std::ofstream fout(argv[2]);

        std::vector<int> nums;
        int num;
        int N;

        fin >> N;
        while (fin >> num) {
            nums.push_back(num);
        }

        std::sort(nums.begin(), nums.end());
        auto opponentSum = std::accumulate(nums.begin(), nums.begin() + N / 2, 0);
        auto ownSum = std::accumulate(nums.begin() + N / 2, nums.end(), 0);

        fout << ownSum - opponentSum;

        fin.close();
        fout.close();
    }
    else {
        std::cout << "Must be 2 arguments: input and output files";
    }
    return 0;
}
