// https://leetcode.com/problems/get-equal-substrings-within-budget/submissions/2029066432
// (Previous attempt: https://leetcode.com/problems/get-equal-substrings-within-budget/submissions/2029064940)

// Added by LeetCode in the background
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <string>

class Solution {
public:
    int equalSubstring(std::string s, std::string t, int maxCost) {
        /* We track
           - the beginning index of our substring,
           - the cost of our current substring, and
           - the longest substring length we've seen so far.
        */
        size_t substringStartIndex = 0;
        int substringCost = 0;
        size_t longestLength = 0;
        /* We then test setting the end of our substring to each
           set of characters in the two strings.
        */
        for (size_t substringEndIndex = 0; substringEndIndex < s.size(); ++substringEndIndex) {
            /* Update the cost for our substring. */
            substringCost += std::abs(t[substringEndIndex] - s[substringEndIndex]);
            /* If the cost exceeds our max cost, the substring from the
               beginning index to the current character set is too long. We
               shorten the substring from the beginning, updating the cost
               each time, until the substring cost is tolerable again.
               In the worst-case scenario, this will remove every character
               up through endIndex inclusive, causing substringCost to drop
               back to its initial value of 0. Since one of our constraints
               is that 0 <= maxCost, the while loop will stop there,
               ensuring A. we eventually terminate and B. startIndex at most
               can become endIndex + 1, while the very next iteration we
               will increment endIndex, so startIndex <= endIndex will still
               be maintained.
            */
            while (substringCost > maxCost) {
                substringCost -= std::abs(t[substringStartIndex] - s[substringStartIndex]);
                ++substringStartIndex;
            }
            /* We then calculate the substring's length, and update the 
               tracker if it's indeed a new longest.
               (This actually only needs to run if the while loop above
               doesn't trigger, but I am testing if avoiding that
               conditional makes the program run faster.)
            */
            longestLength = std::max(longestLength, substringEndIndex - substringStartIndex + 1);
        }
        /* We then return the longest substring length we encountered,
           or the default 0 if no valid substrings were actually discovered.
        */
        return longestLength;
    }
};