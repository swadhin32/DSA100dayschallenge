/*
Problem 43: Linked List Cycle
Problem Statement

Given the head of a linked list, determine whether the linked list has a cycle.

A cycle exists if some node points back to a previous node.

Example

Input:

1 → 2 → 3 → 4
↑ ↓
← ← ←

Output:

true

Core Intuition

Use two pointers:

Slow pointer moves 1 step
Fast pointer moves 2 steps

If a cycle exists:

fast eventually catches slow

Like two runners on a circular track 🏃💨
*/








class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;

            fast = fast->next->next;

            if(slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};