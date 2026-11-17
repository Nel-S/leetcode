// https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/submissions/2022616003

// Provided in the background by LeetCode
#include <vector>

class Solution {
public:
    int movesToMakeZigzag(std::vector<int>& nums) {
        /* Two possible zigzag arrays could be formed from the current one:
           one where we're shrinking only even indices, or one where we're
           shrinking only odd indices. We track how many moves would
           need to be made to form either. 
        */
        int totalIfOddsAreGreater = 0, totalIfEvensAreGreater = 0;
        /* For each element in the array: */
        for (size_t i = 0; i < nums.size(); ++i) {
            /* The amount the element would need to shrink to be less than
               its left neighbor is 0 if it doesn't have a left
               neighbor/its left neighbor is already greater, or
               nums[i] - nums[i - 1] + 1 otherwise.
            */
            int neededLeftShrinkage = !i || nums[i - 1] > nums[i] ? 0 : nums[i] - nums[i - 1] + 1;
            /* The amount the element would need to shrink to be less than
               its right neighbor is 0 if it doesn't have a right
               neighbor/its right neighbor is already greater, or
               nums[i] - nums[i + 1] + 1 otherwise.
            */
            int neededRightShrinkage = (i == nums.size() - 1) || nums[i + 1] > nums[i] ? 0 : nums[i] - nums[i + 1] + 1;
            /* The value only needs to shrink by whichever of those two
               required values is greater. We then add that to the relevant 
               zigzag pattern counter depending on the index's parity.
            */
            (i & 1 ? totalIfOddsAreGreater : totalIfEvensAreGreater) += std::max(neededLeftShrinkage, neededRightShrinkage);
        }
        // Return whichever necessary total would be lower.
        return std::min(totalIfOddsAreGreater, totalIfEvensAreGreater);
    }
};
