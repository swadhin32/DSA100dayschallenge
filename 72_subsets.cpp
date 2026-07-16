/* 72. Subsets
    Pattern: Backtracking

Problem Statement:
Given an integer array nums of unique elements,
return all possible subsets (the power set).

The solution set must not contain duplicate subsets.

Example:

Input:
nums = [1,2,3]

Output:
[
[],
[1],
[2],
[3],
[1,2],
[1,3],
[2,3],
[1,2,3]
]

Explanation:
Every element has two choices:

* take it
* don’t take it

Total subsets:
2^n

Core Concepts:
✅ Backtracking
✅ Recursion Tree
✅ Include / Exclude Pattern
✅ Power Set Generation

Main Logic:
For every element:

* include it in subset
* exclude it from subset

Recursively explore both decisions.

Important Insight:
Subset problems are the purest form of recursion tree thinking 🌲

For n elements:
every level creates:
👉 “take”
or
👉 “not take”

Binary decision explosion 💥

━━━━━━━━━━━━━━━━━━

⚔️ Welcome to Backtracking World:

Trees:
“Traverse existing structure.”

Backtracking:
“Create and explore possibilities.”

Now recursion becomes a maze explorer 🧩🔥 */




class Solution {
public:

    vector<vector<int>> ans;

    void backtrack(vector<int>& nums,
                   int index,
                   vector<int>& current)
    {
        if(index == nums.size())
        {
            ans.push_back(current);
            return;
        }

        // TAKE
        current.push_back(nums[index]);

        backtrack(nums, index + 1, current);

        current.pop_back();

        // NOT TAKE
        backtrack(nums, index + 1, current);
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> current;

        backtrack(nums, 0, current);

        return ans;
    }
};