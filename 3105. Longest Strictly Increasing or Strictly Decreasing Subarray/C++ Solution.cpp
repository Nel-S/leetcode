// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/submissions/2194455387

// Added by LeetCode in the background
#include <algorithm>
#include <cstddef>
#include <vector>

class Solution {
public:
    int longestMonotonicSubarray(std::vector<int>& nums) {
        /* Set multiple tracking variables to their initial values: */
        // Last seen value is first value of vector
        int lastValue = nums[0];
        // Current streaks for both increasing and decreasing are 1
        int strictlyIncreasingStreak = 1, strictlyIncreasingMaxStreak = 1;
        int strictlyDecreasingStreak = 1, strictlyDecreasingMaxStreak = 1;
        /* Then for the remaining values in the vector: */
        for (size_t i = 1; i < nums.size(); ++i) {
            int currentValue = nums[i];
            // Update decreasing streak: if current value is less than previous, it increments (and possibly sets a new record), otherwise it resets to 1
            if (currentValue < lastValue) {
                ++strictlyDecreasingStreak;
                strictlyDecreasingMaxStreak = std::max(strictlyDecreasingMaxStreak, strictlyDecreasingStreak);
            } else {
                strictlyDecreasingStreak = 1;
            }
            
            // Repeat for increasing streak
            if (currentValue > lastValue) {
                ++strictlyIncreasingStreak;
                strictlyIncreasingMaxStreak = std::max(strictlyIncreasingMaxStreak, strictlyIncreasingStreak);
            } else {
                strictlyIncreasingStreak = 1;
            }

            // Update last seen value for next iteration
            lastValue = currentValue;
        }
        // Return whichever of the two highest-recorded streaks was larger.
        return std::max(strictlyIncreasingMaxStreak, strictlyDecreasingMaxStreak);
    }
};
