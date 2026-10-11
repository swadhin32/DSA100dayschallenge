/*
94. Merge K Sorted Lists
    Pattern: Heap + Linked List

Problem Statement:
You are given an array of k linked lists,
where each linked list is sorted in ascending order.

Merge all the linked lists into one sorted linked list and return its head.

Example:

Input:

lists = [
1 → 4 → 5,
1 → 3 → 4,
2 → 6
]

Output:

1 → 1 → 2 → 3 → 4 → 4 → 5 → 6

Explanation:
All nodes from the k sorted linked lists are combined while maintaining sorted order.

Core Concepts:
✅ Min Heap / Priority Queue
✅ Linked List
✅ K-Way Merge
✅ Greedy Selection

Main Logic:

* Put the first node of every non-empty list into a min heap.
* The smallest node is always at the top.
* Remove the smallest node and add it to the result.
* Move to its next node.
* Add that next node to the heap.
* Continue until the heap becomes empty.

Important Insight:
Because every individual list is already sorted,
we only need to compare the smallest available node from each list.

This is the same core idea used in:
👉 K-way merging
👉 External sorting
👉 Merging multiple sorted data streams

━━━━━━━━━━━━━━━━━━

⚡ New Pattern Unlocked:

Task Scheduler → Prioritize by Frequency

Merge K Sorted Lists → Prioritize by Value

Both problems teach the same powerful idea:

👉 Keep the most important candidates in a Heap
👉 Always process the best available candidate first 🔥
*/


public ListNode MergeKLists(ListNode[] lists)
{
    PriorityQueue<ListNode, int> minHeap =
        new PriorityQueue<ListNode, int>();

    // Put first node of every list into heap
    foreach (ListNode node in lists)
    {
        if (node != null)
        {
            minHeap.Enqueue(node, node.val);
        }
    }

    ListNode dummy = new ListNode(0);
    ListNode current = dummy;

    while (minHeap.Count > 0)
    {
        // Get smallest node
        ListNode smallest = minHeap.Dequeue();

        // Add it to result
        current.next = smallest;
        current = current.next;

        // Add next node from the same list
        if (smallest.next != null)
        {
            minHeap.Enqueue(
                smallest.next,
                smallest.next.val
            );
        }
    }

    return dummy.next;
}