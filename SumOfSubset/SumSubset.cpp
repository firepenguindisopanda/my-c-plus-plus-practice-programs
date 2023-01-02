#include <cassert>
#include <iostream>
#include <vector>
#include <cstring>

/**
 * @brief Dynamic Programming namespace
 *
 */
namespace dynamic_programming
{
    namespace dynamicProgramming
    {
        /**
         * @brief Sum of subset problem
         * @param {std::vector<int>} arr
         * @param {int} n - size of the array
         * @param {int} sum - sum of the required sum to be found
         * @returns {bool} - returns true if the sum of subset is found, else returns false
         *
         */
        bool sumOfSubset(std::vector<int> arr, int n, int sum)
        {
            std::vector<std::vector<bool>> subset(n + 1, std::vector<bool>(sum + 1));
            for (int i = 0; i <= n; i++)
            {
                subset[i][0] = true;
            }
            for (int i = 1; i <= sum; i++)
            {
                subset[0][i] = false;
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= sum; j++)
                {
                    if (j < arr[i - 1])
                    {
                        subset[i][j] = subset[i - 1][j];
                    }
                    if (j >= arr[i - 1])
                    {
                        subset[i][j] = subset[i - 1][j] || subset[i - 1][j - arr[i - 1]];
                    }
                }
            }
            
            return subset[n][sum];
        }
    }
} // namespace dynamic_programming

static void test_one(){
    std::vector<int> arr = {3, 34, 4, 12, 5, 2};
    int n = arr.size();
    int sum = 9;
    bool expected_answer = true;
    bool actual_answer = dynamic_programming::dynamicProgramming::sumOfSubset(arr, n, sum);
    std::cout << "Testing One..." << std::endl;
    assert(actual_answer == expected_answer);
    std::cout << "Passed Test One!" << std::endl;
}

static void test_two(){
    std::vector<int> arr = {3, 34, 4, 12, 5, 2};
    int n = arr.size();
    int sum = 30;
    bool expected_answer = false;
    bool actual_answer = dynamic_programming::dynamicProgramming::sumOfSubset(arr, n, sum);
    std::cout << "Testing Two..." << std::endl;
    assert(actual_answer == expected_answer);
    std::cout << "Passed Test Two!" << std::endl;
}



int main()
{
    test_one();
    test_two();
    system("pause");
    return 0;
}