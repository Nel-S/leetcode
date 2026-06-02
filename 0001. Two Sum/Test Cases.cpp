#include "Solution.cpp"
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
    int target;
    std::vector<int> expectedOutput;
};

const TestCase TEST_CASES[] = {
    {
        {2, 7, 11, 15}, 9,
        {0, 1}
    }, {
        {3, 2, 4}, 6,
        {1, 2}
    }, {
        {3, 3}, 6,
        {0, 1}
    }
};

int main() {
    for (size_t i = 0; i < sizeof(TEST_CASES)/sizeof(*TEST_CASES); ++i) {
        TestCase testCase = TEST_CASES[i];
        std::vector<int> output = Solution().twoSum(testCase.nums, testCase.target);
        if (output == testCase.expectedOutput) {
            std::printf("Test case %zd passed.\n", i + 1);
        } else {
            std::printf("!!! TEST CASE %zd FAILED. !!!\n", i + 1);
            // Nums
            std::printf("\tNums: ");
            printVector(testCase.nums);
            std::printf("\n");
            // Target
            std::printf("\tTarget: %d\n", testCase.target);
            // Actual output
            std::printf("\tActual output: ");
            printVector(output);
            std::printf("\n");
            // Expected output
            std::printf("\tExpected output: ");
            printVector(testCase.expectedOutput);
            std::printf("\n");
            break;
        }
    }
}