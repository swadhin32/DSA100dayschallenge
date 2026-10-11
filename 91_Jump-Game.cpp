/*
91. Jump Game
    Pattern: Greedy

Problem Statement:
You are given an integer array nums.

You are initially positioned at the first index of the array.
The value at each index represents the maximum jump length from that position.

Return true if you can reach the last index, otherwise return false.

Example 1:

Input:
nums = [2,3,1,1,4]

Output:
true

Explanation:
Start at index 0.
You can jump to index 1, then from index 1 jump to the last index.

One possible path:
0 → 1 → 4

Example 2:

Input:
nums = [3,2,1,0,4]

Output:
false

Explanation:
You eventually reach index 3, where nums[3] = 0.
From there, you cannot move forward to reach the last index.

Core Concepts:
✅ Greedy Algorithm
✅ Array Traversal
✅ Reachability
✅ Maintaining Farthest Position

Main Logic:
Keep track of the farthest index that can currently be reached.

For every index:

* If the current index is beyond the farthest reachable position → return false.
* Otherwise, update the farthest reachable position.

Important Insight:
You don’t need to try every possible jump.

At every position, only ask:
👉 “What is the farthest position I can reach from here?”

If the farthest reachable index reaches the last index,
the answer is true.
*/


class Solution {
public:

    bool canJump(vector<int>& nums)
    {
        int farthest = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(i > farthest)
                return false;

            farthest =
                max(farthest,
                    i + nums[i]);

            if(farthest >= nums.size() - 1)
                return true;
        }

        return true;
    }
};