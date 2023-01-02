#include <cassert>
#include <iostream>
#include <vector>
#include <cstring>

/**
 * @brief Search namespace
 * 
 */
namespace search {
    /**
     * @brief Rabin Karp namespace
     * 
     */
    namespace rabin_karp {
        /**
         * @brief Rabin Karp search algorithm
         * @param {char} text
         * @param {char} pattern
         * @param {int} primeNum
         * @returns {void} - prints the index of the pattern in the text if found, else prints no match found
         * 
         */
        void rabinKarp(char text[], char pattern[], int primeNum) {
            int pattern_length = strlen(pattern);
            int text_length = strlen(text);
            int i {}, j {}, pattern_hash {0}, text_hash {0}, h {1};

            // The value of h would be "pow(d, M-1)%q"
            for (i = 0; i < pattern_length - 1; i++) {
                h = (h * 256) % primeNum;
            }

            /**
             * @brief Calculate the hash value of the pattern and 
             * the first window of the text
             * 
             */
            for (i = 0; i < pattern_length; i++) {
                pattern_hash = (256 * pattern_hash + pattern[i]) % primeNum;
                text_hash = (256 * text_hash + text[i]) % primeNum;
            }

            /**
             * @brief Slide the patter over text one by one
             * 
             */
            for (i = 0; i <= text_length - pattern_length; i++) {
                /**
                 * @brief Check the hash values of the current window of text
                 * and the pattern. If the hash values match then only check
                 * for the characters one by one
                 * 
                 */
                if (pattern_hash == text_hash) {
                    /**
                     * @brief Check for characters one by one
                     * 
                     */
                    for (j = 0; j < pattern_length; j++) {
                        if (text[i + j] != pattern[j]) {
                            break;
                        }
                    }

                    /**
                     * @brief If the pattern is found, print the index
                     * 
                     */
                    if (j == pattern_length) {
                        std::cout << "Pattern found at index " << i << std::endl;
                    }
                }

                /**
                 * @brief Calculate the hash value for the next window of text
                 * 
                 */
                if (i < text_length - pattern_length) {
                    text_hash = (256 * (text_hash - text[i] * h) + text[i + pattern_length]) % primeNum;

                    /**
                     * @brief We might get negative value of t, converting it to positive
                     * 
                     */
                    if (text_hash < 0) {
                        text_hash = (text_hash + primeNum);
                    }
                }
            }
        }
    }
}


int main() {
    char text[] = "AABCAB12AFAABCABFFEGABCAB";
    char pattern[] = "ABCAB";
    int primeNum = 101; // A prime number

    search::rabin_karp::rabinKarp(text, pattern, primeNum);

    system("pause");
    return 0;
}