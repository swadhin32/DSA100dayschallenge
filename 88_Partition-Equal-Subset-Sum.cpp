/*
88. Partition Equal Subset Sum
    Pattern: Knapsack DP

Problem Statement:
Given an integer array nums,
return true if you can partition the array into two subsets such that the sum of elements in both subsets is equal.

Example 1:

Input:
nums = [1,5,11,5]

Output:
true

Explanation:
The array can be partitioned into:
[1,5,5] and [11]

Both subsets have sum = 11.

Example 2:

Input:
nums = [1,2,3,5]

Output:
false

Explanation:
No equal partition exists.

Core Concepts:
✅ Dynamic Programming
✅ 0/1 Knapsack
✅ Subset Sum
✅ Decision DP

Main Logic:

1. Find total sum.
2. If total sum is odd → impossible.
3. Target = totalSum / 2.
4. Check if a subset with sum = target exists.

DP State:

dp[i] =
whether sum i can be formed.

Important Insight:
Partition Equal Subset Sum is actually a disguised Subset Sum problem.

Once you recognize the target becomes totalSum/2,
the problem transforms into a classic 0/1 Knapsack DP.

━━━━━━━━━━━━━━━━━━

🏰 DP Evolution:

Count Ways → Optimize Profit → Minimize Operations → Compare Strings → Solve Knapsack

Dynamic Programming isn’t about memorizing formulas.

It’s about identifying:
👉 State
👉 Transition
👉 Base Case

Master these three, and hundreds of DP problems become approachable. 🧠🔥
*/


class Solution {
public:

    bool canPartition(vector<int>& nums)
    {
        int sum = 0;

        for(int x : nums)
            sum += x;

        if(sum % 2)
            return false;

        int target = sum / 2;

        vector<bool> dp(target+1,false);

        dp[0]=true;

        for(int num : nums)
        {
            for(int s=target;
                s>=num;
                s--)
            {
                dp[s] =
                    dp[s] ||
                    dp[s-num];
            }
        }

        return dp[target];
    }
};