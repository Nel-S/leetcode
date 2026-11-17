// https://leetcode.com/problems/rotate-array/submissions/2196428326

// Added by LeetCode in the background
#include <cstddef>
#include <numeric>
#include <vector>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        /* If k = a*(nums.size()) + b, then rotating by k will involve
           a full rotations (which don't change the array at all) followed by a partial rotation by b entries. As such, we can shrink k to simply the interval [0, nums.size() - 1].        
         */
        size_t reducedK = static_cast<size_t>(k) % nums.size();
        /* If the reduced k is 0, we would perform exclusively full 
           rotations, and the array would not change. */
        if (!reducedK) return;
        /* To make iterating easier, we actually perform a left rotation by nums.size() - reducedK elements, which is identical to a right rotation by reducedK elements. */
        reducedK = nums.size() - reducedK;
        /* To achieve O(1) storage, we will store one element, overwrite
           its position with the element that would replace it; overwrite
           *that element's* position with the element that would replace
           it; and so on down the line. Then at the end we reinsert the
           original stored element.
           If we simply increment by reducedK modulo nums.size() each time,
           we will follow a "cycle" that loops around the array (possibly
           multiple times), hitting different elements of the array, and
           eventually ending at the element we began from. The elements
           that cycle hits will be gcd(reducedK, nums.size()) entries apart.
        */
        size_t cycleGap = std::gcd(nums.size(), reducedK);
        /* Therefore, we need a cycle beginning at index 0, a cycle 
           beginning at index 1, ..., a cycle beginning at index
           cycleGap - 1. All other elements will be hit during one of those 
           cycles. */
        for (size_t cycleStart = 0; cycleStart < cycleGap; ++cycleStart) {
            /* Then for the current cycle: */
            // Backup the initial value
            int cycleStartBackup = nums[cycleStart];
            /* Repeatedly 
               - determine the next index in the cycle, and
               - replace the current index's value.
               We stop right when nextIndex == cycleStart again, at which 
               point the next iteration would have been identical to the
               first iteration ( = we've completed a full loop).
               (We actually could stop this loop one iteration earlier, but that might make the logic slightly messier.)
            */
            size_t currentIndex, nextIndex = cycleStart;
            do {
                currentIndex = nextIndex;
                nextIndex = (currentIndex + reducedK) % nums.size();
                nums[currentIndex] = nums[nextIndex];
            } while (nextIndex != cycleStart);
            /* At this point, nextIndex is cycleStart, and currentIndex is 
               the index reducedK elements before cycleStart, where
               cycleStart's original value should have been written. We
               manually insert the backed-up value there.
             */
            nums[currentIndex] = cycleStartBackup;
        }
        /* The array's now rotated in O(n) time (since each cycle hit a unique set of numbers exactly once) and O(1) space. */
    }
};
