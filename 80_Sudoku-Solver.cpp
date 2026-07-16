/* 80. Sudoku Solver
    Pattern: Advanced Backtracking

Problem Statement:
Write a program to solve a Sudoku puzzle by filling the empty cells.

Rules:

1. Each row must contain digits 1-9 exactly once.
2. Each column must contain digits 1-9 exactly once.
3. Each 3×3 sub-box must contain digits 1-9 exactly once.

Empty cells are represented by ‘.’.

Example:

Input:

5 3 . | . 7 . | . . .
6 . . | 1 9 5 | . . .
. 9 8 | . . . | . 6 .

8 . . | . 6 . | . . 3
4 . . | 8 . 3 | . . 1
7 . . | . 2 . | . . 6

. 6 . | . . . | 2 8 .
. . . | 4 1 9 | . . 5
. . . | . 8 . | . 7 9

Output:
A completely solved valid Sudoku board.

Core Concepts:
✅ Backtracking
✅ Constraint Satisfaction
✅ Recursive Search
✅ State Validation

Main Logic:
For every empty cell:

* Try digits 1 to 9
* Check if placement is valid
* If valid:
    * place digit
    * recursively solve remaining board
* If stuck:
    * remove digit (backtrack)

Important Insight:
Sudoku is the “boss battle” of classical backtracking.

The algorithm is simply:

Try → Validate → Recurse → Undo

Repeated thousands of times until a valid board emerges.

━━━━━━━━━━━━━━━━━━

⚔️ Backtracking Kingdom Completed (80 Problems)

You have now mastered:

✅ Subsets
✅ Combinations
✅ Permutations
✅ Parentheses Generation
✅ Grid Search
✅ N Queens
✅ String Partitioning
✅ Constraint Satisfaction
✅ Sudoku Solving

Next Kingdom Ahead:

🏰 Dynamic Programming (DP) 🏰

Backtracking:
“Explore every possibility.”

Dynamic Programming:
“Remember previous work and never solve the same thing twice.” 🔥 */






class Solution {
public:

    bool isValid(
        vector<vector<char>>& board,
        int row,
        int col,
        char num)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==num)
                return false;

            if(board[i][col]==num)
                return false;
        }

        int boxRow=(row/3)*3;
        int boxCol=(col/3)*3;

        for(int r=boxRow;
            r<boxRow+3;
            r++)
        {
            for(int c=boxCol;
                c<boxCol+3;
                c++)
            {
                if(board[r][c]==num)
                    return false;
            }
        }

        return true;
    }

    bool solve(
        vector<vector<char>>& board)
    {
        for(int row=0; row<9; row++)
        {
            for(int col=0; col<9; col++)
            {
                if(board[row][col]=='.')
                {
                    for(char num='1';
                        num<='9';
                        num++)
                    {
                        if(isValid(
                            board,
                            row,
                            col,
                            num))
                        {
                            board[row][col]=num;

                            if(solve(board))
                                return true;

                            board[row][col]='.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(
        vector<vector<char>>& board)
    {
        solve(board);
    }
};