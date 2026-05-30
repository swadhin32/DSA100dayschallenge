/*
Palindrome Linked List

Problem Statement:
Given the head of a singly linked list, determine whether it is a palindrome.

Example:

Input:
1 → 2 → 2 → 1

Output:
true

Core Idea:

Find middle
Reverse second half
Compare both halves

Pattern:
Fast/Slow Pointer + Reverse Linked List
*/
















class Solution {
public:

    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = nullptr;

        while(head != nullptr)
        {
            ListNode* nextNode = head->next;

            head->next = prev;

            prev = head;

            head = nextNode;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;

            fast = fast->next->next;
        }

        ListNode* secondHalf = reverse(slow);

        ListNode* firstHalf = head;

        while(secondHalf != nullptr)
        {
            if(firstHalf->val != secondHalf->val)
            {
                return false;
            }

            firstHalf = firstHalf->next;

            secondHalf = secondHalf->next;
        }

        return true;
    }
};
