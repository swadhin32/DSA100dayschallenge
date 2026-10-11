/*
87. Edit Distance
    Pattern: String DP

Problem Statement:
Given two strings word1 and word2,
return the minimum number of operations required to convert word1 into word2.

You are allowed to perform only the following operations:

* Insert a character
* Delete a character
* Replace a character

Example 1:

Input:
word1 = “horse”
word2 = “ros”

Output:
3

Explanation:
horse → rorse (Replace ‘h’ with ‘r’)
rorse → rose (Delete ‘r’)
rose → ros (Delete ‘e’)

Example 2:

Input:
word1 = “intention”
word2 = “execution”

Output:
5

Core Concepts:
✅ Dynamic Programming
✅ String Transformation
✅ 2D DP
✅ Minimum Operations

Main Logic:
If current characters match:

dp[i][j] = dp[i-1][j-1]

Otherwise:

Take minimum among:

* Insert
* Delete
* Replace

Transition:

dp[i][j] =
1 + min(
Insert,
Delete,
Replace
)

Important Insight:
This problem teaches how DP can model transformations between two states.

It is widely used in:

* Spell Checkers
* Auto Correction
* DNA Sequence Analysis
* Text Comparison Tools

━━━━━━━━━━━━━━━━━━*/

class Solution {
public:

    int minDistance(string word1,
                    string word2)
    {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(
            n+1,
            vector<int>(m+1)
        );

        for(int i=0;i<=n;i++)
            dp[i][0]=i;

        for(int j=0;j<=m;j++)
            dp[0][j]=j;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=1+
                        min({
                            dp[i-1][j],     // delete
                            dp[i][j-1],     // insert
                            dp[i-1][j-1]    // replace
                        });
                }
            }
        }

        return dp[n][m];
    }
};