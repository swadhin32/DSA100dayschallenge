/*
🧩 PROBLEM 32: FIND PEAK ELEMENT

Problem Statement:

A peak element is an element that is greater than its neighbors.

Given an integer array nums, find any peak element index.

You may assume:

nums[-1] = -∞
nums[n] = -∞

👉 Return the index of any one peak.

You must solve it in O(log n) time.

Example 1:

Input:
nums = [1,2,3,1]

Output:
2

Explanation:
3 is a peak element.

Example 2:

Input:
nums = [1,2,1,3,5,6,4]

Output:
5

Explanation:
6 is a peak element.
*/




/*
Problem: Find Peak Element

Pattern: Binary Search
Key Idea:
If right side is bigger → peak lies right
Else → peak lies left
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {1,2,3,1};

    int l = 0, r = nums.size() - 1;

    while(l < r) {
        int mid = (l + r) / 2;

        if(nums[mid] < nums[mid + 1])
            l = mid + 1;
        else
            r = mid;
    }

    cout << l; // peak index
}