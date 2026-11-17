// https://leetcode.com/problems/valid-palindrome/submissions/2021947203

#include <cctype>
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        /* The overarching idea is that we can iterate inwards from both
           ends of the string, and compare each newly-encountered 
           alphanumeric character to make sure both sides still match.
        */
        /* These track the current left and right indices. */
        ssize_t leftIndex = 0, rightIndex = s.length() - 1;
        /* LeftIndex increases by one, and RightIndex shrinks by one, after
           every single iteration, so they are guaranteed to eventually pass
           each other and cause this infinite loop to be broken out of.
        */
        while (true) {
            /* Move the left index forward until it hits an alphanumeric
               character or leaves the string.
            */
            while (leftIndex < s.length() && !std::isalpha(s[leftIndex]) && !std::isdigit(s[leftIndex])) ++leftIndex;
            /* Move the right index backward until it hits an alphanumeric
               character or leaves the string. (This is why the indices are
               ssize_t instead of size_t.)
            */
            while (rightIndex >= 0 && !std::isalpha(s[rightIndex]) && !std::isdigit(s[rightIndex])) --rightIndex;
            /* If the indices have passed each other, the whole string
               has been checked while still being a palindrome, so we
               return success. Since leftIndex will always be >=0 and
               rightIndex will always be <= s.length() - 1, this also
               will catch if either index left the string.
            */
            if (leftIndex > rightIndex) return true;
            /* Otherwise convert the two characters to lowercase (or leave
               the same for digits). If the two differ, we no longer have
               a palindrome, so return failure.
            */
            if (std::tolower(s[leftIndex]) != std::tolower(s[rightIndex])) return false;
            /* Afterwards, move leftIndex and rightIndex off the characters
               that were just checked, for the next iteration.
            */
            ++leftIndex, --rightIndex;
        }
    }
};