/* 81. Climbing Stairs
    Pattern: DP Basics

Problem Statement:
You are climbing a staircase.

It takes n steps to reach the top.

Each time you can either:

* climb 1 step
* climb 2 steps

Return the number of distinct ways to reach the top.

Example 1:

Input:
n = 2

Output:
2

Explanation:

1. 1 + 1
2. 2

Example 2:

Input:
n = 3

Output:
3

Explanation:

1. 1 + 1 + 1
2. 1 + 2
3. 2 + 1

Core Concepts:
✅ Dynamic Programming
✅ Recursion to DP Conversion
✅ Memoization
✅ Fibonacci Pattern

Main Logic:
To reach step n:

* come from step (n-1)
* come from step (n-2)

Therefore:

ways(n) = ways(n-1) + ways(n-2)

Important Insight:
This is the “Hello World” of Dynamic Programming.

The same pattern appears in:

* Fibonacci
* Tiling Problems
* Counting Paths */







class Solution {
public:

    vector<int> dp;

    int solve(int n)
    {
        if(n <= 2)
            return n;

        if(dp[n] != -1)
            return dp[n];

        return dp[n] =
            solve(n-1) +
            solve(n-2);
    }

    int climbStairs(int n)
    {
        dp.resize(n+1,-1);

        return solve(n);
    }
};