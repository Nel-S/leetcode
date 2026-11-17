// https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/submissions/2158502138

// Added by LeetCode in the background
#include <algorithm>
#include <cstddef>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<int> maxDepthAfterSplit(std::string seq) {
        // Allocate output vector with the same size as the original string.
        std::vector<int> out = std::vector<int>(seq.size());

        /* We then record the depth that each parentheses exists at, as well as the maximum depth seen.
            Our grammar is such that every left parentheses triggers a new depth, and every right parentheses ends one, so
            we can determine this in O(n) time with a single left-to-right pass. 
        */
        int currentDepth = 0, maxDepth = 0;
        for (size_t i = 0; i < seq.size(); ++i) {
            // Left parentheses increase the depth by one.
            if (seq[i] == '(') {
                ++currentDepth;
                out[i] = currentDepth;
                // This is also the only situation where a new maximum depth can be reached.
                maxDepth = std::max(currentDepth, maxDepth);
            // Right parentheses decrease the depth by one, *after* the character has been parsed.
            } else {
                out[i] = currentDepth;
                --currentDepth;
            }
        }

        /* Since we now know the depth of every symbol in the array, and the maximum overall depth, we can split the symbols based on whether they're in the upper/lower half of the range of depths.
        This will result in one sequence having depth ceil(maxDepth/2.) and the other floor(maxDepth/2.), which is the most even split possible.
        */
        int cutoff = maxDepth/2;
        for (size_t i = 0; i < out.size(); ++i) {
            out[i] = (out[i] > cutoff);
        }

        // Return output vector.
        return out;
    }
};