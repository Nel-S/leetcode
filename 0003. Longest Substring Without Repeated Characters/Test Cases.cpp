#include "Solution.cpp"
#include <cstdio>

struct TestCase {
    std::string s;
    int expectedOutput;
};

const TestCase TEST_CASES[] = {
    {
        "abcabcbb",
        3
    }, {
        "bbbbb",
        1
    }, {
        "pwwkew",
        3
    }, {
        " ",
        1
    }
};

int main() {
    for (size_t i = 0; i < sizeof(TEST_CASES)/sizeof(*TEST_CASES); ++i) {
        TestCase testCase = TEST_CASES[i];
        int output = Solution().lengthOfLongestSubstring(testCase.s);
        if (output == testCase.expectedOutput) {
            std::printf("Test case %zd passed.\n", i + 1);
        } else {
            std::printf("!!! TEST CASE %zd FAILED. !!!\n", i + 1);
            // S
            std::printf("\tS: \"%s\"\n", testCase.s.c_str());
            // Actual output
            std::printf("\tActual output: %d\n", output);
            // Expected output
            std::printf("\tExpected output: %d\n", testCase.expectedOutput);
            break;
        }
    }
}