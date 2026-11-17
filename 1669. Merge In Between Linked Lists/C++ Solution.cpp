// https://leetcode.com/problems/merge-in-between-linked-lists/submissions/2196486391

// Added by LeetCode in the background
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // Using a different pointer (to preserve list1's head pointer), iterate to node list1[a-1] (or at worst the end of list1 as a failsafe).
        ListNode *keptTraversalNode = list1;
        for (int i = 0; i < a - 1 && keptTraversalNode->next; ++i) keptTraversalNode = keptTraversalNode->next;
        // Create pointer to list1[a], then redirect list1[a-1].next to list2[0].
        ListNode *removedTraversalNode = keptTraversalNode->next;
        keptTraversalNode->next = list2;
        // Iterate from list1[a] to list1[b+1] (or at worst the end of list1 as a failsafe).
        // (Also attempt to delete each removed node.)
        for (int i = a; i <= b && removedTraversalNode->next; ++i) {
            ListNode *pointerToDeletedNode = removedTraversalNode;
            removedTraversalNode = removedTraversalNode->next;
            delete pointerToDeletedNode;
        }
        // Iterate to the end of list2, which is node list2[m-1].
        while (keptTraversalNode->next) keptTraversalNode = keptTraversalNode->next;
        // Redirect list2[m-1].next to list1[b+1], and return the original list1 head pointer.
        keptTraversalNode->next = removedTraversalNode;
        return list1;
    }
};
