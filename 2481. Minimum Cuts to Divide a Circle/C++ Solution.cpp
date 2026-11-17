#ifndef LEETCODE_2481_CPP
#define LEETCODE_2481_CPP

// https://leetcode.com/problems/minimum-cuts-to-divide-a-circle/submissions/2021441873

class Solution {
public:
    int numberOfCuts(int n) {
        /* n == 1 is the whole circle, and thus requires no cuts.
           We also catch invalid (non-positive) values of n here.
        */
        if (n <= 1) return 0;
        /* If there are an odd number of slices, no full-length cuts can be
           applied. (Otherwise we would have to fit (n - 1)/2 slices on one
           half of the circle, and (n + 1)/2 slices on the other half,
           which there is no way to do while ensuring every slice is
           equally-sized.)
           Therefore we can only apply half-length cuts, for which we have
           to apply n to divide the circle into n sections.
        */
        if (n & 1) {
            return n;
        }
        /* Oherwise if there are an even number of slices, we can apply a
           full-length cut to divide the circle into two
           rotationally-symmetric halves. The first half needs to be
           divided into n/2 equal-sized slices, which requires n/2 - 1
           cuts--and by making every cut full-length, each cut will extend
           to the other half of the circle and create n/2 equal-sized
           slices on that half as well. Therefore we need
           1 + n/2 - 1 == n/2 total cuts.
        */
        return n/2;
    }
};

#endif