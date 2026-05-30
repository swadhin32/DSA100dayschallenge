/*
Problem Statement:
Given the head of a singly linked list, return the middle node.

If two middle nodes exist, return the second middle node.

Example:

Input:
1 → 2 → 3 → 4 → 5

Output:
3

Core Idea:

Slow pointer moves 1 step
Fast pointer moves 2 steps
When fast reaches end,
slow automatically reaches middle

Pattern:
Fast & Slow Pointer
*/








class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;

            fast = fast->next->next;
        }

        return slow;
    }
};