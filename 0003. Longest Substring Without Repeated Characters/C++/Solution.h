#ifndef LEETCODE_0003_CPP
#define LEETCODE_0003_CPP

// https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/2019886751

// Added by LeetCode in the background
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /* This holds which characters are in the current substring the
           algorithm's examining.
        */
        std::unordered_set<char> currentSubstringCharacters;
        /* This is what index the current substring the algorithm's
           examining begins at.
        */
        size_t substringStartIndex = 0;
        /* This is the size of the longest substring so far. */
        size_t longestSubstring = 0;
        /* For each character in the substring: */
        for (size_t substringEndIndex = 0; substringEndIndex < s.length(); ++substringEndIndex) {
            const char currentCharacter = s[substringEndIndex];
            /* If the character's not part of the current substring, we
               can simply add it to the end of our running substring and
               keep it intact.
               The indices are already in the right places, so that solely 
               requires adding it to our "seen" set.
            */
            if (
            // --------------------------------------------------------------
            // ORIGINAL SOLUTION:
            //    !currentSubstringCharacters.contains(currentCharacter)
            // FOR ENVIRONMENTS BEFORE C++20:
               currentSubstringCharacters.find(currentCharacter) == currentSubstringCharacters.end()
            // --------------------------------------------------------------
            ) {
                currentSubstringCharacters.insert(currentCharacter);
                continue;
            }
            /* Otherwise, our current substring, from its beginning up
               through wherever the current character previously appeared,
               will be invalidated.
               We update the length if it was longer than the previous 
               record: substringEndIndex currently points to the index 
               *after* our full substring, so its length is
               (substringEndIndex - 1) - substringStartIndex + 1
               = substringEndIndex - substringStartIndex.
            */
            longestSubstring = std::max(longestSubstring, substringEndIndex - substringStartIndex);
            /* Then, iterating from the substring's beginning until the 
               current character is encountered, we remove each character
               from the "seen" set.
            */
            while (s[substringStartIndex] != currentCharacter) {
                currentSubstringCharacters.erase(s[substringStartIndex]);
                ++substringStartIndex;
            }
            /* substringStartIndex now is at the previous location of
               currentCharacter in the substring. We increment the index
               one final time to remove it from the substring, but since 
               the character itself is still part of the new substring--
               just now at its end instead of its beginning--there's no
               need to remove it from the "seen" set.
            */
            ++substringStartIndex;
        }
        /* In case the entire string contains distinct characters, we 
           try to update longestSubstring one last time with the final
           substring examined.
        */
        longestSubstring = std::max(longestSubstring, s.length() - substringStartIndex);
        /* LeetCode wants this as an int instead of a size_t, so we cast
           the value and return it.
        */
        return static_cast<int>(longestSubstring);
    }
};

#endif