#include "Solution.cpp"
#include <cstdio>

struct TestCase {
    std::string s;
    bool expectedOutput;
};

const TestCase TEST_CASES[] = {
    {
        "0",
        true
    }, {
        "e",
        false
    }, {
        ".",
        false
    }, {
        "2",
        true
    }, {
        "0089",
        true
    }, {
        "-0.1",
        true
    }, {
        "+3.14",
        true
    }, {
        "4.",
        true
    }, {
        "-.9",
        true
    }, {
        "2e10",
        true
    }, {
        "-90E3",
        true
    }, {
        "3e+7",
        true
    }, {
        "+6e-1",
        true
    }, {
        "53.5e93",
        true
    }, {
        "-123.456e789",
        true
    }, {
        "abc",
        false
    }, {
        "1a",
        false
    }, {
        "1e",
        false
    }, {
        "e3",
        false
    }, {
        "99e2.5",
        false
    }, {
        "--6",
        false
    }, {
        "-+3",
        false
    }, {
        "95a54e53",
        false
    }
};

int main() {
    for (size_t i = 0; i < sizeof(TEST_CASES)/sizeof(*TEST_CASES); ++i) {
        TestCase testCase = TEST_CASES[i];
        bool output = Solution().isNumber(testCase.s);
        if (output == testCase.expectedOutput) {
            std::printf("Test case %zd passed.\n", i + 1);
        } else {
            std::printf("!!! TEST CASE %zd FAILED. !!!\n", i + 1);
            // S
            std::printf("\tS: \"%s\"\n", testCase.s.c_str());
            // Actual output
            std::printf("\tActual output: %s\n", output ? "true" : "false");
            // Expected output
            std::printf("\tExpected output: %s\n", testCase.expectedOutput ? "true" : "false");
            break;
        }
    }
}