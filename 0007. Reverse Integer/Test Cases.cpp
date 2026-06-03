#include "Solution.cpp"
#include <cstdio>

struct TestCase {
    int x;
    int expectedOutput;
};

const struct TestCase TEST_CASES[] = {
    {
        123,
        321
    }, {
        -123,
        -321
    }, {
        120,
        21
    }, {
        0,
        0
    }, {
        -2147483648,
        0
    }, {
        2147483647,
        0
    }, {
        -2147483640,
        -463847412
    }, {
        120000000,
        21
    }
};

int main() {
    for (size_t i = 0; i < sizeof(TEST_CASES)/sizeof(*TEST_CASES); ++i) {
        struct TestCase testCase = TEST_CASES[i];
        int output = Solution().reverse(testCase.x);
        if (output == testCase.expectedOutput) {
            printf("Test case %zd passed.\n", i + 1);
        } else {
            printf("!!! TEST CASE %zd FAILED. !!!\n", i + 1);
            // X
            printf("\tX: %d\n", testCase.x);
            // Actual output
            printf("\tActual output: %d\n", output);
            // Expected output
            printf("\tExpected output: %d\n", testCase.expectedOutput);
            break;
        }
    }
}