/*Problem Statement:
You are given the heads of two sorted linked lists.

Merge them into one sorted linked list and return the head of the merged list.

Example:

Input:
List1: 1 → 2 → 4
List2: 1 → 3 → 4

Output:
1 → 1 → 2 → 3 → 4 → 4

Core Idea:

Compare nodes from both lists
Smaller node gets attached first
Move that list forward
Continue until one list finishes
Attach remaining nodes

Pattern:
Linked List + Two Pointer Merge
*/













class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode dummy(0);

        ListNode* tail = &dummy;

        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val <= list2->val)
            {
                tail->next = list1;

                list1 = list1->next;
            }
            else
            {
                tail->next = list2;

                list2 = list2->next;
            }

            tail = tail->next;
        }

        if(list1 != nullptr)
        {
            tail->next = list1;
        }

        if(list2 != nullptr)
        {
            tail->next = list2;
        }

        return dummy.next;
    }
};