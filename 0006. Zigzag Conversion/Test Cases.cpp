#include "Solution.cpp"
#include <cstdio>

struct TestCase {
    std::string s;
    int numRows;
    std::string expectedOutput;
};

const TestCase TEST_CASES[] = {
    {
        "PAYPALISHIRING", 3,
        "PAHNAPLSIIGYIR"
    }, {
        "PAYPALISHIRING", 4,
        "PINALSIGYAHRPI"
    }, {
        "A", 1,
        "A"
    }, {
        "PAYPALISHIRING", 10,
        "PAYPALGINSIHRI"
    }, {
        ".", 2,
        "."
    }
};

int main() {
    for (size_t i = 0; i < sizeof(TEST_CASES)/sizeof(*TEST_CASES); ++i) {
        TestCase testCase = TEST_CASES[i];
        std::string output = Solution().convert(testCase.s, testCase.numRows);
        if (output == testCase.expectedOutput) {
            std::printf("Test case %zd passed.\n", i + 1);
        } else {
            std::printf("!!! TEST CASE %zd FAILED. !!!\n", i + 1);
            // S
            std::printf("\tS: \"%s\"\n", testCase.s.c_str());
            // NumRows
            std::printf("\tNumRows: %d\n", testCase.numRows);
            // Actual output
            std::printf("\tActual output: \"%s\"\n", output.c_str());
            // Expected output
            std::printf("\tExpected output: \"%s\"\n", testCase.expectedOutput.c_str());
            break;
        }
    }
}