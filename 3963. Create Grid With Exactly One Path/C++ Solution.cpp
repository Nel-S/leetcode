// https://leetcode.com/problems/create-grid-with-exactly-one-path/submissions/2183369535

// Added by LeetCode in the background
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> createGrid(int m, int n) {
        /* We solve this problem by simply creating the grid
            .####
            .####
            .####
            .....
           simply expanded to fill an mxn size.
           This involves two types of rows: ".###[...]#" for the first m-1
           rows, and "....[...]." for the last row.
         */
        // We first construct the two strings.
        std::string lastRow = ".", otherRow = ".";
        for (int i = 1; i < n; ++i) {
            lastRow += ".";
            otherRow += "#";
        }

        // We then create the output vector, containing m-1 otherRow's and 1 lastRow.
        std::vector<std::string> output;
        for (int i = 0; i < m - 1; ++i) {
            output.push_back(otherRow);
        }
        output.push_back(lastRow);
        // Return the output.
        return output;
    }
};