// https://leetcode.com/problems/two-sum/submissions/2017798006
// (https://leetcode.com/problems/two-sum/submissions/2017782671 is faster, but has no comments)

// Provided in the background by LeetCode
#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        /* For two numbers A and B to be able to sum to Target (assuming
           without loss of generality that A <= B), A must be <= Target/2,
           and B must be >= Target/2. (Otherwise if both are < Target/2, the
           sum will be less than Target, and if both are > Target/2, the sum
           will be greater than Target.)
           To that end, the basic idea is that if we sorted Nums, we could
           iterate from the left side of the vector to try values for A, and
           iterate from the right side of the vector to try values for B.
           The values from the left side are monotonically-increasing, 
           while the values from the right side are 
           monotonically-decreasing--so if the sum is too low, we can
           increase A, and if the sum is too high, we can decrease B. If
           the two meet (since the problem stated the same element can't be
           used twice), no valid options remain and no solution can
           therefore exist.

           Sorting takes (on average) O(n*log(n)) time, and all iterating
           takes O(n) time, so this algorithm runs in O(n*log(n)).
        */

        /* Since the solution asks for the indices in the original Num
           array, not the sorted Num array, we need to track what indices 
           each of Nums' values originally belonged to. We create another
           vector with entries of the form
           {Nums entry, original index in Nums}.
        */
        std::vector<std::pair<int, size_t>> numsWithIndices(nums.size());
        for (size_t i = 0; i < nums.size(); ++i) numsWithIndices[i] = std::pair<int, size_t>(nums[i], i);
        /* We then sort the new vector based on the Nums values in each 
           pair.
        */
        std::sort(numsWithIndices.begin(), numsWithIndices.end());
        /* We initially start with the index 0 for A and length-1 for B.*/
        size_t leftIndex = 0, rightIndex = numsWithIndices.size() - 1;
        /* So long as the two don't collide: */
        while (leftIndex < rightIndex) {
            /* Get the current sum */
            int sum = numsWithIndices[leftIndex].first + numsWithIndices[rightIndex].first;
            /* As mentioned above, if the sum is too low, check the next
               value for A (>= to the current one)
            */
            if (sum < target) ++leftIndex;
            /* If the sum is too low, check the next value for B (<= to the
               current one)
            */
            else if (sum > target) --rightIndex;
            /* Otherwise the sum matches. Create a new vector with A and
               B's original Nums indices, and return it
            */
            else {
                std::vector<int> solution(2);
                solution[0] = numsWithIndices[leftIndex].second;
                solution[1] = numsWithIndices[rightIndex].second;
                return solution;
            }
        }
        /* If we reach here, no solution was found, so we just return an
           empty vector.
        */
        return std::vector<int>();
    }
};
