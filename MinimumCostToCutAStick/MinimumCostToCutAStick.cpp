#include <algorithm> // for sort function
#include <cassert>   // for assert function
#include <iostream>
#include <vector>

namespace dynamic_programming
{
    /**
     * @brief dynamic programming namespace
     *
     */
    namespace dynamicProgramming
    {
        int dfs(std::vector<int> &cuts, int start, int end)
        {
            if (start + 1 == end)
            {
                return 0;
            }
            int minCost = INT_MAX;
            for (int i = start + 1; i < end; i++)
            {
                int cost = dfs(cuts, start, i) + dfs(cuts, i, end) + cuts[end] - cuts[start];
                minCost = std::min(minCost, cost);
            }
            return minCost;
        }
        /**
         * @brief Minimum cost to cut a stick
         *
         */
        int minCostToCutAStick(std::vector<int> &cuts, int n)
        {
            cuts.push_back(0);
            cuts.push_back(n);
            std::sort(cuts.begin(), cuts.end());
            return dfs(cuts, 0, cuts.size() - 1);
        }
    }
}

static void test_one(){
    std::vector<int> cuts = {1, 3, 4, 5};
    int n = 7;
    int expected_answer = 16;
    int actual_answer = dynamic_programming::dynamicProgramming::minCostToCutAStick(cuts, n);
    std::cout << "Testing One..." << std::endl;
    assert(actual_answer == expected_answer);
    std::cout << "Test One Passed..." << std::endl;
}

static void test_two(){
    std::vector<int> cuts = {5, 6, 1, 4, 2};
    int n = 9;
    int expected_answer = 22;
    int actual_answer = dynamic_programming::dynamicProgramming::minCostToCutAStick(cuts, n);
    std::cout << "Testing Two..." << std::endl;
    assert(actual_answer == expected_answer);
    std::cout << "Test Two Passed..." << std::endl;
}

int main() {
    test_one();
    test_two();
    system("pause");
    return 0;
}