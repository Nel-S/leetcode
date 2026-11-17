// https://leetcode.com/problems/largest-number-at-least-twice-of-others/submissions/2184347121

#include <cstddef>
#include <vector>

class Solution {
public:
    int dominantIndex(std::vector<int>& nums) {
        /* Since nums is guaranteed to have at least two integers, we initialize the largest and second-largest numbers' indices using the first two elements.
        Since the largest integer is guaranteed to be unique, the largest's index is whichever of nums[0] and nums[1] is greater; the second-largest is simply the other one.*/
        int largestIndex = nums[0] > nums[1] ? 0 : 1;
        int secondLargestIndex = 1 - largestIndex;
        // For every other number in the vector:
        for (size_t i = 2; i < nums.size(); ++i) {
            // If it's a new largest, update both largestIndex and secondLargestIndex
            if (nums[i] > nums[largestIndex]) {
                secondLargestIndex = largestIndex;
                largestIndex = i;
            // Otherwise if it's a new second-largest, update just secondLargestIndex
            } else if (nums[i] > nums[secondLargestIndex]) {
                secondLargestIndex = i;
            }
            // Otherwise nothing need be done
        }
        // Perform the check, and return the largest index or -1 respectively.
        return nums[largestIndex] >= 2*nums[secondLargestIndex] ? largestIndex : -1;
    }
};