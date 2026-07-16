/* 84. Coin Change
    Pattern: Unbounded Knapsack DP

Problem Statement:
You are given an integer array coins representing coins of different denominations and an integer amount.

Return the fewest number of coins needed to make up that amount.

If it is impossible to make up the amount, return -1.

You may use each coin an unlimited number of times.

Example 1:

Input:
coins = [1,2,5]
amount = 11

Output:
3

Explanation:
11 = 5 + 5 + 1

Example 2:

Input:
coins = [2]
amount = 3

Output:
-1

Explanation:
It is impossible to make amount 3 using only coin 2.

Core Concepts:
✅ Dynamic Programming
✅ Unbounded Knapsack
✅ Minimum Optimization
✅ State Transition

Main Logic:
For every amount from 1 to target:

* Try every coin
* If coin can be used:
    * take minimum of current answer and
        1 + answer for remaining amount

Transition:

dp[i] = min(dp[i], 1 + dp[i - coin])

Important Insight:
Unlike 0/1 Knapsack,
coins can be used unlimited times.

This is the foundation for many “minimum cost” and “minimum steps” DP problems.

━━━━━━━━━━━━━━━━━━

🏰 DP Evolution:

Climbing Stairs → Count Ways
House Robber → Maximize Profit
House Robber II → Handle Circular Constraint
Coin Change → Minimize Cost

Dynamic Programming is no longer just remembering answers.
It’s about designing the right state and transition. 🧠🔥 */





class Solution {
public:

    int coinChange(vector<int>& coins,
                   int amount)
    {
        vector<int> dp(
            amount + 1,
            amount + 1
        );

        dp[0] = 0;

        for(int i=1;i<=amount;i++)
        {
            for(int coin : coins)
            {
                if(i >= coin)
                {
                    dp[i] =
                        min(
                            dp[i],
                            1 + dp[i-coin]
                        );
                }
            }
        }

        if(dp[amount] > amount)
            return -1;

        return dp[amount];
    }
};