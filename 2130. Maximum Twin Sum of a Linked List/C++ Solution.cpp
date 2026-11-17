// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/submissions/2193460771

// Added by LeetCode in the background
#include <algorithm>
#include <climits>
#include <cstddef>
#include <stack>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        // First iterate through linked list to measure its length.
        ListNode *iterator = head;
        size_t listLength = 1;
        while (iterator->next) {
            iterator = iterator->next;
            ++listLength;
        }

        // Iterate through first half of linked list again, storing each of its elements in a LIFO stack.
        std::stack<int> nodeStack;
        iterator = head;
        for (size_t i = 0; i < listLength/2; ++i, iterator = iterator->next) {
            nodeStack.push(iterator->val);
        }

        // Then iterate through second half of linked list, pairing up each node with its corresponding stack element, and tracking the largest summed pair.
        int maxPairSum = INT_MIN;
        while (iterator) {
            maxPairSum = std::max(maxPairSum, iterator->val + nodeStack.top());
            nodeStack.pop();
            iterator = iterator->next;
        }
        // Return the maximum summed pair.
        return maxPairSum;
    }
};