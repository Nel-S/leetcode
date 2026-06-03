#ifndef LEETCODE_0002_CPP
#define LEETCODE_0002_CPP

// https://leetcode.com/problems/add-two-numbers/submissions/2017888693

// Provided in the background by LeetCode
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /* This algorithm is no different than digit-by-digit
           grade-school addition: the current digits and any
           carries are added, the sum mod 10 is set to the current
           digit, and the sum's multiple of 10 becomes the next carry.
        */
        
        /* To simplify the looping logic, Solution will initially point
           to a "sentinel node", whose Next pointer is where we will
           build the actual digit-by-digit number from. We then simply
           return solution->next at the end.*/
        /* TODO: To save a fraction of time, we could theoretically
           hijack l1 and simply overwrite it with the solution,
           extending it as necessary.*/
        ListNode *solution = new ListNode();
        /* The initial carry is 0.*/
        int l1Digit, l2Digit, carry = 0;
        /* Iterating through the solution's linked list so long as
           l1 still exists, l2 still exists, or a carry still exists:
        */
        for (ListNode *currentPointer = solution; l1 || l2 || carry;
                currentPointer = currentPointer->next
        ) {
            /* If l1 hasn't reached its end yet, pull the next digit
               from it. Otherwise its next digit defaults to 0.*/
            if (l1) {
                l1Digit = l1->val;
                l1 = l1->next;
            } else l1Digit = 0;
            /* If l2 hasn't reached its end yet, pull the next digit
               from it. Otherwise its next digit defaults to 0.*/
            if (l2) {
                l2Digit = l2->val;
                l2 = l2->next;
            } else l2Digit = 0;
            /* Calculate the sum, and set the current digit and carry
               appropriately.*/
            int sum = l1Digit + l2Digit + carry;
            currentPointer->next = new ListNode(sum % 10);
            carry = sum/10; // (note: integer division)
        }
        return solution->next;
    }
};

#endif