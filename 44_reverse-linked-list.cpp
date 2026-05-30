/*
Problem 44: Reverse Linked List
Problem Statement

Reverse a singly linked list.

Example

Input:

1 → 2 → 3 → 4 → 5

Output:

5 → 4 → 3 → 2 → 1

Core Intuition

Each node points forward.

We must reverse every arrow.

Important Visualization

Current situation:

1 → 2 → 3

After reversing first link:

1 ← 2   3

Danger:
if we directly reverse pointer,
remaining list gets lost.

So we need:

prev
curr
nextNode

Classic pointer dance 🧵⚔️

Steps

For every node:

store next
reverse link
move prev
move curr
*/



class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr != nullptr)
        {
            ListNode* nextNode = curr->next;

            curr->next = prev;

            prev = curr;

            curr = nextNode;
        }

        return prev;
    }
};