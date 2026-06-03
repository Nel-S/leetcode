#include "Solution.h"
#include <stdio.h>

struct TestCase {
    int n;
    int expectedOutput;
};

const struct TestCase TEST_CASES[] = {
    {
        1,
        0
    }, {
        2,
        1
    }, {
        3,
        3
    }, {
        4,
        2
    }, {
        5,
        5
    }, {
        6,
        3
    }, {
        7,
        7
    }, {
        8,
        4
    }, {
        9,
        9
    }, {
        10,
        5
    }, {
        11,
        11
    }, {
        12,
        6
    }, {
        13,
        13
    }, {
        14,
        7
    }
};

int main() {
    for (size_t i = 0; i < sizeof(TEST_CASES)/sizeof(*TEST_CASES); ++i) {
        struct TestCase testCase = TEST_CASES[i];
        int output = numberOfCuts(testCase.n);
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