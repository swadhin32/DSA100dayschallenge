/* 71. Combination Sum
    Pattern: Backtracking

Problem Statement:
Given an array of distinct integers candidates
and a target integer target,
return all unique combinations of candidates
where the chosen numbers sum to target.

You may use the same number unlimited times.

Return the combinations in any order.

Example:

Input:
candidates = [2,3,6,7]
target = 7

Output:
[
[2,2,3],
[7]
]

Explanation:

* 2 + 2 + 3 = 7
* 7 itself also forms target

Example 2:

Input:
candidates = [2,3,5]
target = 8

Output:
[
[2,2,2,2],
[2,3,3],
[3,5]
]

Core Concepts:
✅ Backtracking
✅ Recursion Tree Exploration
✅ Decision Making
✅ Combination Generation

Main Logic:
At every index:

* choose current number
* stay at same index (reuse allowed)
* or skip current number

Backtracking explores all possible paths.

Important Insight:
Backtracking is basically:
👉 “Try → Explore → Undo”

Recursive exploration engine 🔥 */





class Solution {
public:

    vector<vector<int>> ans;

    void backtrack(vector<int>& candidates,
                   int target,
                   int index,
                   vector<int>& current)
    {
        if(target == 0)
        {
            ans.push_back(current);
            return;
        }

        if(target < 0 || index >= candidates.size())
        {
            return;
        }

        // TAKE
        current.push_back(candidates[index]);

        backtrack(candidates,
                  target - candidates[index],
                  index,
                  current);

        current.pop_back();

        // SKIP
        backtrack(candidates,
                  target,
                  index + 1,
                  current);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) 
    {
        vector<int> current;

        backtrack(candidates, target, 0, current);

        return ans;
    }
};