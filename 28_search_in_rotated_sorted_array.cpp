/*
Problem Statement:

You are given a sorted array that has been rotated at some unknown pivot.

Find the index of a given target element.
If the target is not present, return -1.

You must solve it in O(log n) time.

Example 1:

Input:
nums = [4,5,6,7,0,1,2]
target = 0

Output:
4

Example 2:

Input:
nums = [4,5,6,7,0,1,2]
target = 3

Output:
-1

Example 3:

Input:
nums = [1]
target = 0

Output:
-1
*/

/*
Problem: Search in Rotated Sorted Array

Given a rotated sorted array,
find index of target in O(log n)

Example:
[4,5,6,7,0,1,2], target = 0 → Output: 4

Pattern: Binary Search (modified)
Key Idea:
At least one half is always sorted
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    int l = 0, r = nums.size() - 1;

    while(l <= r) {
        int mid = (l + r) / 2;

        if(nums[mid] == target) {
            cout << mid;
            return 0;
        }

        // Left half sorted
        if(nums[l] <= nums[mid]) {
            if(nums[l] <= target && target < nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        // Right half sorted
        else {
            if(nums[mid] < target && target <= nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }

    cout << -1;
}