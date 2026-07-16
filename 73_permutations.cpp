/* 73. Permutations
    Pattern: Backtracking

Problem Statement:
Given an array nums of distinct integers,
return all possible permutations.

You can return the answer in any order.

A permutation means:
different possible arrangements of elements.

Example:

Input:
nums = [1,2,3]

Output:
[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]

Explanation:
All possible orderings of elements are generated.

Core Concepts:
✅ Backtracking
✅ Recursive Exploration
✅ Used Array / Swapping Technique
✅ Arrangement Problems

Main Logic:
At every step:

* choose one unused element
* add it to current permutation
* recursively build remaining positions
* backtrack after returning

Important Insight:
Combination problems care about:
👉 selection

Permutation problems care about:
👉 ordering

That single difference changes the entire recursion tree ⚡
 */



 class Solution {
public:

    vector<vector<int>> ans;

    void backtrack(vector<int>& nums,
                   vector<int>& current,
                   vector<bool>& used)
    {
        if(current.size() == nums.size())
        {
            ans.push_back(current);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(used[i])
                continue;

            used[i] = true;

            current.push_back(nums[i]);

            backtrack(nums, current, used);

            current.pop_back();

            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> current;

        vector<bool> used(nums.size(), false);

        backtrack(nums, current, used);

        return ans;
    }
};