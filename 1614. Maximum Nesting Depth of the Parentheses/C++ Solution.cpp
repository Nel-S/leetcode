// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/submissions/2158509504

// Added by LeetCode in the background
#include <algorithm>
#include <string>

class Solution {
public:
    int maxDepth(std::string s) {
        int currentDepth = 0, maximumDepth = 0;
        // For each character in the string:
        for (const char &character : s) {
            // Each left parentheses increases the current depth by one.
            if (character == '(') {
                ++currentDepth;
                // This is also the only situation where a new maximum depth can be reached.
                maximumDepth = std::max(currentDepth, maximumDepth);
            // Each right parentheses decreases the current depth by one.
            } else if (character == ')') {
                --currentDepth;
            }
            // Every other character does not change the current depth.
        }
        // Return the maximum seen.
        return maximumDepth;
    }
};