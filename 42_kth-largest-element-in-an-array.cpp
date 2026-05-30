/*
Problem 42: Kth Largest Element in an Array
Problem Statement

Given an integer array nums and an integer k, return the kth largest element in the array.

Example

Input:

nums = [3,2,1,5,6,4]
k = 2

Output:

5

Explanation:

Sorted descending:

6 5 4 3 2 1

2nd largest element = 5

Intuition

Use a Min Heap of size k.

The heap always stores the top k largest elements.

The smallest among them remains at the top.

That top element becomes the kth largest element.
*/














#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int num : nums)
        {
            minHeap.push(num);

            if(minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};