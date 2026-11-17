// https://leetcode.com/problems/adding-spaces-to-a-string/submissions/2158523325

// Added by LeetCode in the background
#include <cstddef>
#include <string>
#include <vector>

class Solution {
public:
    std::string addSpaces(std::string s, std::vector<int>& spaces) {
        // Create new string, with size equals to |s| + |spaces|, containing solely spaces.
        std::string out = std::string(s.size() + spaces.size(), ' ');

        /* Then, for each character in the string, we copy it to the new string.
        However, we offset the destination's index by the number of spaces that had been inserted prior to that character.
        */
        int spacesEncountered = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (spacesEncountered < spaces.size() && i >= spaces[spacesEncountered]) {
                ++spacesEncountered;
            }
            out[i + spacesEncountered] = s[i];
        }

        // Return the output string.
        return out;
    }
};