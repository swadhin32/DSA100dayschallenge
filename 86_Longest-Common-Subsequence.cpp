/* 86. Longest Common Subsequence (LCS)
    Pattern: 2D DP

Problem Statement:
Given two strings text1 and text2,
return the length of their longest common subsequence.

A subsequence is a sequence that appears in the same relative order but not necessarily contiguously.

Example 1:

Input:
text1 = “abcde”
text2 = “ace”

Output:
3

Explanation:
The longest common subsequence is:
“ace”

Example 2:

Input:
text1 = “abc”
text2 = “abc”

Output:
3

Example 3:

Input:
text1 = “abc”
text2 = “def”

Output:
0

Core Concepts:
✅ 2D Dynamic Programming
✅ String Matching
✅ Subsequences
✅ State Transition

Main Logic:
If characters match:

dp[i][j] = 1 + dp[i-1][j-1]

Otherwise:

dp[i][j] = max(dp[i-1][j], dp[i][j-1])

Important Insight:
LCS is one of the most fundamental DP problems.

It forms the basis for:

* Edit Distance
* Diff Tools
* DNA Sequence Matching
* Version Control Systems
* Spell Checking

━━━━━━━━━━━━━━━━━━

🏰 DP Progression:

Climbing Stairs → Count Ways
House Robber → Maximize Profit
Coin Change → Minimize Coins
Longest Increasing Subsequence → Optimize Subsequences
Longest Common Subsequence → Compare Two Sequences

You’re now entering the heart of Dynamic Programming, where designing the correct state becomes the key to solving complex problems. 🧠🔥 */






class Solution {
public:

    int longestCommonSubsequence(
        string text1,
        string text2)
    {
        int n=text1.size();
        int m=text2.size();

        vector<vector<int>> dp(
            n+1,
            vector<int>(m+1,0)
        );

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=
                        1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=
                        max(
                            dp[i-1][j],
                            dp[i][j-1]
                        );
                }
            }
        }

        return dp[n][m];
    }
};