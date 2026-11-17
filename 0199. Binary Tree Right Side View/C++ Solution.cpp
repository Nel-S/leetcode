// https://leetcode.com/problems/binary-tree-right-side-view/submissions/2193449644

// Added by LeetCode in the background
#include <cstddef>
#include <vector>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Helper recursive function
    void recursiveTraversal(TreeNode* node, size_t depth, std::vector<int> &visibleValues) {
        // If the current node doesn't exist, return early.
        if (!node) return;
        // If we are at a depth lower than any seen before, add the value to the visibleValues array.
        if (visibleValues.size() < depth) visibleValues.push_back(node->val);
        /* Explore the right branch first. (This means that if two nodes exist at the same depth, the right one will be added to the array instead of the left one.) */
        recursiveTraversal(node->right, depth+1, visibleValues);
        // Then explore the left branch.
        recursiveTraversal(node->left, depth+1, visibleValues);
    }

    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> visibleValues;
        // Recursively traverse the tree, starting from the root, and adding to visibleValues as we go along.
        recursiveTraversal(root, 1, visibleValues);
        // Return the result.
        return visibleValues;
    }
};