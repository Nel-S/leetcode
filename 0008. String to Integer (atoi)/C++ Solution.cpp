// https://leetcode.com/problems/string-to-integer-atoi/submissions/2197589584

// Added by LeetCode in the background
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <string>

class Solution {
public:
    int myAtoi(std::string s) {
        // From checking the C++ standard, apparently the solution **does work** without this,
        // but it's only guaranteed to for C++11, which doesn't seem great in my opinion.
        if (!s.size()) return 0;

        size_t i = 0;
        // Ignore leading whitespace
        while (s[i] == ' ') ++i;

        // Indicate if negative
        bool isNegative = (s[i] == '-');
        // Advance stream only if a sign was provided
        if (s[i] == '-' || s[i] == '+') ++i;

        // Ignore leading zeroes
        while (s[i] == '0') ++i;

        int64_t value = 0;
        // While the current character is a digit, and the value hasn't overflowed the 32-bit range:
        while (s[i] >= '0' && s[i] <= '9' && value <= INT64_C(1) << 31) {
            // Derive current digit as an integer, and add it to value's running total
            int64_t digit = s[i] - '0';
            value = 10*value + digit;
            ++i;
        }
        // Update value's sign if necessary, and clamp to 32-bit range
        value = isNegative ?
            std::max(-value, static_cast<int64_t>(INT32_MIN)) :
            std::min(value, static_cast<int64_t>(INT32_MAX));
        // Convert value to 32 bits and return
        return static_cast<int>(value);
    }
};