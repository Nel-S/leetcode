// https://leetcode.com/problems/find-the-difference/submissions/2184349299

// Added by LeetCode in the background
#include <algorithm>
#include <cstddef>
#include <string>

class Solution {
public:
    char findTheDifference(std::string s, std::string t) {
        // We first sort both strings.
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        /* The two strings are now *almost* the same, except for the one inserted letter, which will simply offset the remainder of t from s.
        As such, we iterate through s until s and t deviate, at which case the letter causing the deviation is the inserted letter.*/
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] != t[i]) return t[i];
        }
        // Otherwise, since t is one letter longer than s, if the first |s| characters of t match s, the inserted letter must be the remaining last letter.
        return t.back();
    }
};