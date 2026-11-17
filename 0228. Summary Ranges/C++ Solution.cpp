// https://leetcode.com/problems/summary-ranges/submissions/2029102306

// Added by LeetCode in the background
#include <cstddef>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        /* The array of summary strings we'll eventually output. */
        std::vector<std::string> ranges;
        /* It's possible that nums is an empty array. In that case,
           the array of summary strings should be empty, and we simply
           return it without doing anything else.
        */
        if (!nums.size()) return ranges;
        /* Otherwise we keep track of the current summary range's beginning,
           initialized at the first element. */
        int rangeBeginning = nums[0];
        /* For each ending index in the array: */
        for (size_t i = 1; i < nums.size(); ++i) {
            /* Nothing need be done if the current index is simply the
               next one in sequence.
            */
            if (nums[i] == nums[i - 1] + 1) continue;
            /* Otherwise, we print the previous range, which extended
               from rangeBeginning through i-1.
            */
            ranges.push_back(
                std::to_string(rangeBeginning) + (
                    /* If rangeBeginning *was* i-1, we don't need to print
                       the arrow and ending index.
                    */
                    nums[i - 1] == rangeBeginning ?
                    "" :
                    /* Otherwise we do. */
                    "->" + std::to_string(nums[i - 1])
                )
            );
            /* Update the next range's beginning to the current element. */
            rangeBeginning = nums[i];
        }
        /* Since we always printed the *previous* range in the loop above,
           we must unfortunately repeat ourselves to print the final
           summary range (from the final rangeBeginning through the end of
           the array).
        */
        ranges.push_back(
            std::to_string(rangeBeginning) + (
                nums.back() == rangeBeginning ?
                "" :
                "->" + std::to_string(nums.back())
            )
        );
        /* Return the list of summary ranges. */
        return ranges;
    }
};