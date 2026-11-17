// https://leetcode.com/problems/palindrome-number/submissions/2197758843
// (Previous attempt: https://leetcode.com/problems/palindrome-number/submissions/2197597109/)

// Added by LeetCode in the background
#include <cmath>

class Solution {
public:
    bool isPalindrome(int x) {
        /* Negative numbers contain the - sign on only one end, and so will 
           never be palindromic. */
        if (x < 0) return false;
        // Otherwise single-digit numbers will always be palindromic.
        if (x < 10) return true;

        // Derive the largest power of 10 <= x.
        int lowestPowerOfTen = std::pow(10, std::floor(std::log10(x)));
        // While x still contains nonzero digits:
        while (x) {
            /* Derive first digit of x, last digit of x, and compare them 
               together. If they differ, the number is no longer 
               palindromic.*/
            int firstDigit = x / lowestPowerOfTen;
            int lastDigit = x % 10;
            if (firstDigit != lastDigit) return false;
            // Remove first and last digits from x.
            x = (x % lowestPowerOfTen) / 10;
            /* Since x was shrunk by two digits, we decrease lowestPowerOfTen by 10^2 = 100.*/
            lowestPowerOfTen /= 100;
        }
        // Otherwise, the number's palindromic.
        return true;
    }
};