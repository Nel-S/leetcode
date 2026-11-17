// https://leetcode.com/problems/climbing-stairs-ii/submissions/2192890993

// Added by LeetCode in the background
#include <algorithm>
#include <cstdint>
#include <vector>

class Solution {
public:
    int climbStairs(int n, std::vector<int>& costs) {
        /* Since each step can only be reached from the three steps before it, we have three
           variables track the costs of each last three steps. */
        std::int32_t costOneStepBack = 0, costTwoStepsBack = 0, costThreeStepsBack = 0;
        /* For each new step in the staircase (including the final one): */
        for (const int &cost : costs) {
            // Calculate the current step's minimum possible cost
            std::int32_t currentStepCost = cost + std::min(
                std::min(
                    costOneStepBack + 1,
                    costTwoStepsBack + 4
                ),
                costThreeStepsBack + 9
            );
            // Then propogate the three most recent steps' costs backward
            costThreeStepsBack = costTwoStepsBack;
            costTwoStepsBack = costOneStepBack;
            costOneStepBack = currentStepCost;
        }
        /* We are now on step n+1, and therefore the nth step's minimum cost is the cost
           of the previous step. */
        return costOneStepBack;
    }
};