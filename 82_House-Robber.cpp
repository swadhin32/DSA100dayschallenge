/* 82. House Robber
    Pattern: 1D DP

Problem Statement:
You are a professional robber planning to rob houses along a street.

Each house contains a certain amount of money.

Constraint:
You cannot rob two adjacent houses because it will trigger the alarm.

Return the maximum amount of money you can rob.

Example 1:

Input:
nums = [1,2,3,1]

Output:
4

Explanation:
Rob house 1 and 3.

1 + 3 = 4

Example 2:

Input:
nums = [2,7,9,3,1]

Output:
12

Explanation:
Rob houses:
2 + 9 + 1 = 12

Core Concepts:
✅ Dynamic Programming
✅ Decision Making
✅ Optimization Problems
✅ 1D DP

Main Logic:
For every house:
Option 1:
Skip current house

Option 2:
Rob current house +
best answer till i-2

Transition:

dp[i] =
max(
dp[i-1],
nums[i] + dp[i-2]
)

Important Insight:
At every position:

👉 Take it
or
👉 Leave it

This “take / not take” DP pattern appears in hundreds of problems.

━━━━━━━━━━━━━━━━━━

🏰 Welcome to Dynamic Programming

Backtracking asks:
“Can I explore every path?”

DP asks:
“Why explore the same path twice?” 🧠🔥

The kingdom of optimization has begun ⚔️ */






class Solution {
public:

    int rob(vector<int>& nums)
    {
        int n = nums.size();

        if(n == 1)
            return nums[0];

        vector<int> dp(n);

        dp[0] = nums[0];

        dp[1] = max(nums[0], nums[1]);

        for(int i=2;i<n;i++)
        {
            dp[i] =
                max(
                    dp[i-1],
                    nums[i] + dp[i-2]
                );
        }

        return dp[n-1];
    }
};