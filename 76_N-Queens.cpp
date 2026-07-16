/* 76. N Queens
    Pattern: Backtracking

Problem Statement:
The n-queens puzzle is the problem of placing n queens on an n × n chessboard such that no two queens attack each other.

Return all distinct solutions.

Queens can attack:

* same row
* same column
* same diagonal

Example:

Input:
n = 4

Output:
[
[”.Q..”,
“…Q”,
“Q…”,
“..Q.”],

[”..Q.”,
“Q…”,
“…Q”,
“.Q..”]
]

Explanation:
Each solution represents a valid queen placement.

Core Concepts:
✅ Backtracking
✅ Constraint Satisfaction
✅ Recursive Search
✅ Column & Diagonal Tracking

Main Logic:
For each row:

* try placing queen in every column
* if safe, place queen
* recursively solve next row
* remove queen while backtracking

Important Insight:
N Queens is one of the most famous backtracking problems.

The secret is:
👉 Build solution row by row
👉 Reject invalid placements immediately

This dramatically reduces search space.

━━━━━━━━━━━━━━━━━━

⚔️ Backtracking Upgrade:

Subsets → Choose/Skip
Permutations → Arrange Choices
Parentheses → Valid State Generation
Word Search → Path Exploration
N Queens → Constraint Satisfaction

Now recursion is no longer traversing structures.
It’s searching through a universe of possibilities 🔥♟️ */






class Solution {
public:

    vector<vector<string>> ans;

    bool isSafe(vector<string>& board,
                int row,
                int col,
                int n)
    {
        int r,c;

        r=row;
        while(r>=0)
        {
            if(board[r][col]=='Q')
                return false;
            r--;
        }

        r=row;
        c=col;

        while(r>=0 && c>=0)
        {
            if(board[r][c]=='Q')
                return false;

            r--;
            c--;
        }

        r=row;
        c=col;

        while(r>=0 && c<n)
        {
            if(board[r][c]=='Q')
                return false;

            r--;
            c++;
        }

        return true;
    }

    void solve(int row,
               vector<string>& board,
               int n)
    {
        if(row == n)
        {
            ans.push_back(board);
            return;
        }

        for(int col=0; col<n; col++)
        {
            if(isSafe(board,row,col,n))
            {
                board[row][col]='Q';

                solve(row+1,board,n);

                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(
            n,
            string(n,'.')
        );

        solve(0,board,n);

        return ans;
    }
};