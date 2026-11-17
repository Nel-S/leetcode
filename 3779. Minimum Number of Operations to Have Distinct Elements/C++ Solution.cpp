// https://leetcode.com/problems/minimum-number-of-operations-to-have-distinct-elements/submissions/2029081410

// Added by LeetCode in the background
#include <unordered_set>
#include <vector>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        /* Create an unordered set to track which numbers have been seen so
           far.
        */
        std::unordered_set<int> seenNumbers;
        /* For each element in reverse order: */
        for (ssize_t i = nums.size() - 1; i >= 0; --i) {
            /* If the number has been seen before, it is the last duplicate
               in nums. i/3 + 1 operations will have to be performed to
               reach and remove it, after which point the vector will have
               no more duplicates.
            */
            if (seenNumbers.contains(nums[i])) return i/3 + 1;
            /* Otherwise we mark the current number as having been seen. */
            seenNumbers.insert(nums[i]);
        }
        /* If we reach this point, every element in the vector is distinct,
           and so no operations are necessary in the first place.
        */
        return 0;
    }
};