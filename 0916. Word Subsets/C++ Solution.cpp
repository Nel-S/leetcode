// https://leetcode.com/problems/word-subsets/submissions/2184336439

// Added by LeetCode in the background
#include <algorithm>
#include <cstddef>
#include <string>
#include <utility>
#include <unordered_map>
#include <vector>

class Solution {
public:
    /* Helper function to create a mapping listing the unique characters in the word, and the number of times each one occurred. */
    void countLetters(const std::string &word, std::unordered_map<char, int> &letterCounts) {
        // For each letter in the word:
        for (const char& letter : word) {
            // Set its mapping's entry to 1 if not already present, or increment its count otherwise
            if (!letterCounts.contains(letter)) {
                letterCounts[letter] = 1;
            } else {
                ++letterCounts[letter];
            }
        }
    }

    std::vector<std::string> wordSubsets(std::vector<std::string>& words1, std::vector<std::string>& words2) {
        // Create output vector
        std::vector<std::string> output;

        /* Each "main word" in words1 will be checked to see if it contains the letters of each individual "subword" in words2. The results would be exactly equivalent if all "subwords" were replaced with a single giant word containing the union of all subwords' letters (e.g. instead of checking ["c", "cc", "b"], one can simply check "bcc"). We therefore first determine the combined letter counts necessary to satisfy all subwords, which would equivalently be the letter counts of our giant combined union-of-all-subwords.*/
        std::unordered_map<char, int> combinedLetterCounts;
        // Initialize the letter counts using the first subword
        countLetters(words2[0], combinedLetterCounts);
        // Then for each other subword, determine its own letter count
        for (size_t i = 1; i < words2.size(); ++i) {
            std::unordered_map<char, int> currentLetterCounts;
            countLetters(words2[i], currentLetterCounts);
            // Update the combined letter counts using the new word's letter count: letters that aren't present yet are added, and letters already present are replaced with whichever of the two counts is greater
            for (const std::pair<char, int> &entry : currentLetterCounts) {
                if (!combinedLetterCounts.contains(entry.first)) {
                    combinedLetterCounts[entry.first] = entry.second;
                } else {
                    combinedLetterCounts[entry.first] = std::max(combinedLetterCounts[entry.first], entry.second);
                }
            }
        }

        // Then we iterate though each "main word". For each one, we create a copy of the combined letter counts, to avoid destroying the original.
        for (const std::string& mainWord : words1) {
            std::unordered_map<char, int> combinedLetterCountsCopy = combinedLetterCounts;
            /* Then we reduce the copied letter counts each time a matching letter is found in the main word. Once all needed instances of a letter has been satisfied, we drop it from the mapping. */
            for (const char& letter : mainWord) {
                if (!combinedLetterCountsCopy.contains(letter))
                    continue;
                --combinedLetterCountsCopy[letter];
                if (combinedLetterCountsCopy[letter] <= 0) {
                    combinedLetterCountsCopy.erase(letter);
                }
            }
            /* If all needed instances of letters have been accounted for, the "main word" is "universal" and we add it to the output.
               Otherwise, 1+ letters in the subwords aren't in the main word, and it is not "universal".*/
            if (!combinedLetterCountsCopy.size()) {
                output.push_back(mainWord);
            }
        }
        
        // Return final output list
        return output;
    }
};