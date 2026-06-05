#include "Solution.h"
#include <cstdio>
#include <iostream>

template <class T>
void printVector(const std::vector<T> &vec) {
    std::cout << "[";
    for (const T &value : vec) std::cout << value << ",";
    std::cout << "]";
}

struct TestCase {
    std::vector<int> nums;
    int expectedOutput;
};

const TestCase TEST_CASES[] = {
    {
        {1, 2, 3},
        2
    }, {
        {9, 6, 1, 6, 2},
        4
    }, {
        {1},
        0
    }
};

int main() {
    for (size_t i = 0; i < sizeof(TEST_CASES)/sizeof(*TEST_CASES); ++i) {
        TestCase testCase = TEST_CASES[i];
        int output = Solution().movesToMakeZigzag(testCase.nums);
        if (output == testCase.expectedOutput) {
            std::printf("Test case %zd passed.\n", i + 1);
        } else {
            std::printf("!!! TEST CASE %zd FAILED. !!!\n", i + 1);
            // Nums
            std::printf("\tNums: ");
            printVector(testCase.nums);
            std::printf("\n");
            // Actual output
            std::printf("\tActual output: %d\n", output);
            // Expected output
            std::printf("\tExpected output: %d\n", testCase.expectedOutput);
            break;
        }
    }
}