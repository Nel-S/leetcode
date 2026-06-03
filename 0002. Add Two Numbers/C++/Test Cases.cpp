#include "Solution.h"
#include <cstdio>
#include <iostream>

bool LinkedListsAreEqual(const ListNode *const l1, const ListNode *const l2) {
    const ListNode *currentPointer1 = l1;
    const ListNode *currentPointer2 = l2;
    // While one of the two pointers is not nullptr:
    while (currentPointer1 || currentPointer2) {
        // If one is nullptr and the other isn't, the linked lists differ
        if (!currentPointer1 != !currentPointer2) return false;
        // If the pointers are different (i.e. not both nullptr):
        // (This + the other condition mean that both pointers must be non-nullptrs.)
        if (currentPointer1 != currentPointer2) {
            // If the pointers' values differ, the linked lists differ.
            if (currentPointer1->val != currentPointer2->val) return false;
            // Move to next entry
            currentPointer1 = currentPointer1->next;
            currentPointer2 = currentPointer2->next;
        }
    }
    // Otherwise the linked lists are equal
    return true;
}

void printLinkedList(const ListNode *const list) {
    const ListNode *currentPointer = list;
    std::cout << "[";
    while (currentPointer) {
        std::cout << currentPointer->val << ",";
        currentPointer = currentPointer->next;
    }
    std::cout << "]";
}

struct TestCase {
    ListNode l1, l2, expectedOutput;
};

const TestCase TEST_CASES[] = {
    {
        {2, new (ListNode){4, new (ListNode){3, nullptr}}},
        {5, new (ListNode){6, new (ListNode){4, nullptr}}},
        {7, new (ListNode){0, new (ListNode){8, nullptr}}}
    }, {
        {0, nullptr},
        {0, nullptr},
        {0, nullptr}
    }, {
        {9, new (ListNode){9, new (ListNode){9, new (ListNode){9, new (ListNode){9, new (ListNode){9, new (ListNode){9, nullptr}}}}}}},
        {9, new (ListNode){9, new (ListNode){9, new (ListNode){9, nullptr}}}},
        {8, new (ListNode){9, new (ListNode){9, new (ListNode){9, new (ListNode){0, new (ListNode){0, new (ListNode){0, new (ListNode){1, nullptr}}}}}}}}
    }
};

int main() {
    for (size_t i = 0; i < sizeof(TEST_CASES)/sizeof(*TEST_CASES); ++i) {
        TestCase testCase = TEST_CASES[i];
        ListNode *output = Solution().addTwoNumbers(&testCase.l1, &testCase.l2);
        if (LinkedListsAreEqual(output, &testCase.expectedOutput)) {
            std::printf("Test case %zd passed.\n", i + 1);
        } else {
            std::printf("!!! TEST CASE %zd FAILED. !!!\n", i + 1);
            // L1
            std::printf("\tL1: ");
            printLinkedList(&testCase.l1);
            std::printf("\n");
            // L2
            std::printf("\tL2: ");
            printLinkedList(&testCase.l2);
            std::printf("\n");
            // Actual output
            std::printf("\tActual output: ");
            printLinkedList(output);
            std::printf("\n");
            // Expected output
            std::printf("\tExpected output: ");
            printLinkedList(&testCase.expectedOutput);
            std::printf("\n");
            break;
        }
    }
}