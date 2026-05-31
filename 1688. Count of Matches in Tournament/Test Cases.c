#include <stdio.h>

extern int numberOfMatches(int);

struct TestCase {
    int n;
    int expectedOutput;
};

const struct TestCase TEST_CASES[] = {
    {
        7,
        6
    }, {
        14,
        13
    }
};

int main() {
    for (size_t i = 0; i < sizeof(TEST_CASES)/sizeof(*TEST_CASES); ++i) {
        struct TestCase testCase = TEST_CASES[i];
        int output = numberOfMatches(testCase.n);
        if (output == testCase.expectedOutput) {
            printf("Test case %zd passed.\n", i + 1);
        } else {
            printf("!!! TEST CASE %zd FAILED. !!!\n", i + 1);
            // N
            printf("\tN: %d\n", testCase.n);
            // Actual output
            printf("\tActual output: %d\n", output);
            // Expected output
            printf("\tExpected output: %d\n", testCase.expectedOutput);
            break;
        }
    }
}