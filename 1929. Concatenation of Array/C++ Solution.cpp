// https://leetcode.com/problems/concatenation-of-array/submissions/2023956596
// (Previous attempt: https://leetcode.com/problems/concatenation-of-array/submissions/2023953958)

// Added by LeetCode in the background
#include <vector>

class Solution {
public:
    std::vector<int> getConcatenation(std::vector<int>& nums) {
        /* Create a new vector copying nums' current state. */
        std::vector<int> ans(nums);
        /* Reserve space for up to 2n elements. */
        ans.reserve(2*nums.size());
        /* Then, for each element in nums, add it to the new vector. */
        for (int number : nums) ans.push_back(number);
        /* Return said new vector. */
        return ans;
    }
};