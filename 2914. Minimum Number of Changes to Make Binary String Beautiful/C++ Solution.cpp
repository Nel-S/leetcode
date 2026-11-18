// https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/submissions/2198956705

#include <cstddef>
#include <string>

class Solution {
public:
    int minChanges(std::string s) {
        /* The entirety of s must be broken into substrings, and every
           substring must be of even length, so every substring must begin
           at an even index of s and end at an odd index of s.
           There's no limit or penalty for how many substrings we can break
           s into, so we can divide the entirety of s into two-element
           couplets (s[0] and s[1], s[2] and s[3], etc.) Under that, each
           substring is fine if both s[2k] and s[2k + 1] are the same
           digit, or requires just one change if the two are opposite
           digits.
           That is the maximum number of substrings that s can be broken
           into, and any other division of s would contain longer
           substrings, and with it, the risk that even indices would have
           to be changed as well as odd indices, which would result in the
           same or a greater number of changes. Therefore, that formulation
           has the minimum number of changes.
        */
        int changes = 0;
        // For each odd index in the string:
        for (size_t i = 1; i < s.size(); i += 2) {
            /* A change is required if and only if the two characters in 
               the substring--the current index and the preceding
               index--differ.
            */
            changes += (s[i] != s[i - 1]);
        }
        // Return the total number of changes.
        return changes;
    }
};