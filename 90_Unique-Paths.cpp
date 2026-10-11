/*
90. Unique Paths
    Pattern: Grid DP

Problem Statement:
There is a robot on an m × n grid.

The robot starts at the top-left corner and wants to reach the bottom-right corner.

The robot can only move:

* Right
* Down

Return the total number of unique paths to reach the destination.

Example 1:

Input:
m = 3
n = 7

Output:
28

Example 2:

Input:
m = 3
n = 2

Output:
3

Explanation:
The three possible paths are:

Right → Down → Down

Down → Right → Down

Down → Down → Right

Core Concepts:
✅ Dynamic Programming
✅ Grid Traversal
✅ 2D DP
✅ Counting Paths

Main Logic:
Every cell can be reached from:

* the cell above
* the cell to the left

Transition:

dp[i][j] =
dp[i-1][j] + dp[i][j-1]

Base Case:
The first row and first column each have only one possible path.

Important Insight:
Many grid problems follow the same pattern:

Current Cell =
Combination of Previous Cells

Recognizing this relationship is the key to solving Grid DP problems.

━━━━━━━━━━━━━━━━━━

🏰 Dynamic Programming Kingdom Completed (90 Problems)

You have now mastered:

✅ 1D DP
✅ 2D DP
✅ String DP
✅ Grid DP
✅ Knapsack DP
✅ Sequence DP
✅ Optimization Problems
✅ Counting Problems

Next Kingdom Ahead:

⚡ Greedy Algorithms ⚡

DP asks:
“What is the best answer using all previous knowledge?”

Greedy asks:
“Can the best local decision lead to the global optimum?” 🚀
*/


/* 
class Solution {
public:

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(
            m,
            vector<int>(n,1)
        );

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j] =
                    dp[i-1][j] +
                    dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};*/




/* The above solution uses a 2D DP array to store the number of unique paths to each cell. So the space complexity is O(m*n). */

/*While the below solution uses a 1D DP array to optimize space complexity to O(n). 🔥🔥*/
#include <vector>
class Solution {
public:

    int uniquePaths(int m, int n)
    {
        vector<int> dp(n,1);

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[j] =
                    dp[j] + dp[j-1];
            }
        }

        return dp[n-1];
    }
};