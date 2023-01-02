#include <algorithm> // for sort function
#include <cassert> // for assert function
#include <iostream>
#include <vector>

/**
 * @namespace search
 * @brief Searching algorithm
 */
namespace search {
    /**
     * @brief Binary Search function
     * @namespace binary_search
     */
    namespace binary_search{
        /**
         * @brief The main function which implements binary search
         * @param arr vector to be searched
         * @param target value to search for
         * @return @param int index of target in vector
         */
        uint64_t binarySearch(std::vector<uint64_t> arr, uint64_t target){
            uint64_t low = 0;   // set the lowest point of the search
            uint64_t high = arr.size() - 1; // set the highest point of the search

            while(low <= high){
                uint64_t middle = low + (high - low) / 2; // set the middle point of the search
                /**
                 * @brief Construct a new if object
                 * If the middle point is the val, return that index.
                 * else check if the val is greater than or less than the middle point
                 * and set the next middle point 
                 * For example: if the val is greater than the middle point, set the low point to the middle point + 1
                 * and if the val is less than the middle point, set the high point to the middle point - 1
                 */
                if(target == arr[middle]){
                    return middle; // return the index of the target
                }else if(target > arr[middle]){
                    low = middle + 1;
                }else{
                    high = middle - 1;
                }
            }
            return -1; // return -1 if the target is not found
        }
    } // end of namespace binary_search

} // end of namespace search

static void test_one(){
    std::vector<uint64_t> arr = {{1, 3, 5, 7, 9, 8, 6, 4, 2}};
    std::sort(arr.begin(), arr.end()); // sort the array
    uint64_t expected_answer = 3;
    uint64_t actual_answer = search::binary_search::binarySearch(arr, 4);
    std::cout << "Testing One..." << std::endl;
    assert(actual_answer == expected_answer);
    std::cout << "Passed Test One!" << std::endl;
}

static void test_two(){
    std::vector<uint64_t> arr = {{1, 23, 25, 4, 2}};
    std::sort(arr.begin(), arr.end()); // sort the array
    uint64_t expected_answer = 4;
    uint64_t actual_answer = search::binary_search::binarySearch(arr, 25);
    std::cout << "Testing Two..." << std::endl;
    assert(actual_answer == expected_answer);
    std::cout << "Passed Test Two!" << std::endl;
}

static void test_three(){
    std::vector<uint64_t> arr = {{1, 31, 231, 12, 2, 5, 51, 21, 23, 12, 3}};
    std::sort(arr.begin(), arr.end()); // sort the array
    uint64_t expected_answer = 8;
    uint64_t actual_answer = search::binary_search::binarySearch(arr, 31);
    std::cout << "Testing Three..." << std::endl;
    assert(actual_answer == expected_answer);
    std::cout << "Passed Test Three!" << std::endl;
}

static void test_four(){
    std::vector<uint64_t> arr = {{1, 10, 32, 2, 6, 3, 21, 18, 9}};
    std::sort(arr.begin(), arr.end()); // sort the array
    uint64_t expected_answer = -1;
    uint64_t actual_answer = search::binary_search::binarySearch(arr, 100);
    std::cout << "Testing Four...\nUnable to find target so return would -1" << std::endl;
    assert(actual_answer == expected_answer);
    std::cout<< "Passed Test Four!" << std::endl;
}

int main(){
    test_one();
    test_two();
    test_three();
    test_four();
    system("pause");
    return 0;
}