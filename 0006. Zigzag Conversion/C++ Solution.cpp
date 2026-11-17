// https://leetcode.com/problems/zigzag-conversion/submissions/2020759808

// Added by LeetCode in the background
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        /* numRows = 1 makes no changes whatsoever.
           We also stop in the impossible case where numRows <= 0.
        */
        if (numRows <= 1) return s;

        /* Create an output string with the same length as the original 
           string. Every character in it will eventually be overwritten, so
           the initializing character doesn't matter.
        */
        std::string convertedString(s.length(), '\0');
        /* This meanwhile tracks the current index we're looking at. */
        size_t currentIndex = 0;

        /* Despite the nested for loops, every iteration of these loops
           processes a *unique* character in the original string.
           Therefore this will only repeat as many times as there are
           characters in the original string--taking O(n) time overall.
        */
        /* For each row in the final pattern: */
        for (size_t row = 0; row < numRows; ++row) {
            /* Our pattern repeats every 2*numRows - 2 characters.
               Therefore for each repetition of the pattern:
            */
            for (size_t i = row; i < s.length(); i += 2*numRows - 2) {
                /* The ith character under this formulation corresponds to 
                   the character in the current repetition's vertical bar
                   for that row.
                */
                convertedString[currentIndex++] = s[i];
                /* The i + 2*(numRows - row - 1)th character meanwhile 
                   corresponds to the character in the current repetition's upward-diagonal line for that row.
                   However, that only exists if the current row isn't the
                   first one, isn't the last one, and if there's still space
                   in the string.
                */
                if (row > 0 && row < numRows - 1 && i + 2*(numRows - row - 1) < s.length()) {
                    convertedString[currentIndex++] = s[i + 2*(numRows - row - 1)];
                }
            }
        }

        // Return the new string.
        return convertedString;
    }
};
