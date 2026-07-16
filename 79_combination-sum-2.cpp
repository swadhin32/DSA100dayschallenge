/* 79. Combination Sum II
    Pattern: Backtracking

Problem Statement:
Given a collection of candidate numbers candidates and a target number target,
find all unique combinations where the candidate numbers sum to target.

Unlike Combination Sum I:

* Each number may be used at most once.
* The solution set must not contain duplicate combinations.

Example:

Input:
candidates = [10,1,2,7,6,1,5]
target = 8

Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Explanation:
Each number can be picked only once.
Duplicate combinations are not allowed.

Core Concepts:
✅ Backtracking
✅ Sorting
✅ Duplicate Handling
✅ Combination Generation

Main Logic:

1. Sort the array.
2. At each level:
    * choose current element
    * move to next index (cannot reuse)
3. Skip duplicates:
    * if current number equals previous number at same level, ignore it.

Important Insight:
Combination Sum I:
👉 Reuse allowed

Combination Sum II:
👉 Reuse NOT allowed
👉 Duplicate combinations NOT allowed

This tiny rule change completely changes the recursion tree. */







class Solution {
public:

    vector<vector<int>> ans;

    void backtrack(vector<int>& nums,
                   int target,
                   int start,
                   vector<int>& current)
    {
        if(target == 0)
        {
            ans.push_back(current);
            return;
        }

        if(target < 0)
            return;

        for(int i = start;
            i < nums.size();
            i++)
        {
            if(i > start &&
               nums[i] == nums[i-1])
            {
                continue;
            }

            current.push_back(nums[i]);

            backtrack(
                nums,
                target - nums[i],
                i + 1,
                current
            );

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(
        vector<int>& candidates,
        int target)
    {
        sort(
            candidates.begin(),
            candidates.end()
        );

        vector<int> current;

        backtrack(
            candidates,
            target,
            0,
            current
        );

        return ans;
    }
};