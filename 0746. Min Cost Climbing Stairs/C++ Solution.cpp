// https://leetcode.com/problems/min-cost-climbing-stairs/submissions/2184344122

// Added by LeetCode in the background
#include <algorithm>
#include <cstddef>
#include <vector>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        /* We are guaranteed the staircase has at least length 2.
           The cost to enter, then later leave, step 0 is cost[0]; the minimum cost to enter, then later leave, step 1 is cost[1] (the alternative being cost[0] + cost[1], which since cost[0] >= 0 will always be larger).
         */
        int runningCostTwoStepsAgo = cost[0], runningCostOneStepAgo = cost[1];
        /* Then, for each step after the first two: */
        for (size_t i = 2; i < cost.size(); ++i) {
            // The minimum cost to enter, then later leave, the current step will be the cost of whichever of the last two steps was cheaper to leave (to enter the current step), plus the cost of the current step (to leave it).
            int runningCostCurrent = std::min(runningCostTwoStepsAgo, runningCostOneStepAgo) + cost[i];
            // Then update the past two steps
            runningCostTwoStepsAgo = runningCostOneStepAgo;
            runningCostOneStepAgo = runningCostCurrent;
        }
        // The minimum cost to enter (without needing to leave) the top of the staircase will be the cost of whichever of the last two steps was cheaper to leave.
        return std::min(runningCostTwoStepsAgo, runningCostOneStepAgo);
    }
};