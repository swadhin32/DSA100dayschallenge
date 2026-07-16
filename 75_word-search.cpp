/* 75. Word Search
    Pattern: Grid DFS + Backtracking

Problem Statement:
Given an m x n grid of characters board and a string word,
return true if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are:

* horizontally neighboring
* vertically neighboring

The same cell may not be used more than once in a single word path.

Example:

Input:

board =
[
[‘A’,‘B’,‘C’,‘E’],
[‘S’,‘F’,‘C’,‘S’],
[‘A’,‘D’,‘E’,‘E’]
]

word = “ABCCED”

Output:
true

Explanation:

A → B → C
↓
C
↓
E ← D

forms the word successfully.

Core Concepts:
✅ DFS Traversal
✅ Backtracking
✅ Grid Navigation
✅ Visited Cell Tracking

Main Logic:

* Start DFS from every cell
* Match current character
* Explore 4 directions
* Mark cell visited
* Backtrack after exploration

Important Insight:
This is a classic:
👉 “Explore path, then undo path”

The foundation for many grid DFS problems. */




class Solution {
public:

    bool dfs(vector<vector<char>>& board,
             string& word,
             int r,
             int c,
             int index)
    {
        if(index == word.size())
            return true;

        if(r < 0 || c < 0 ||
           r >= board.size() ||
           c >= board[0].size() ||
           board[r][c] != word[index])
        {
            return false;
        }

        char temp = board[r][c];

        board[r][c] = '#';

        bool found =
            dfs(board, word, r+1, c, index+1) ||
            dfs(board, word, r-1, c, index+1) ||
            dfs(board, word, r, c+1, index+1) ||
            dfs(board, word, r, c-1, index+1);

        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board,
               string word)
    {
        for(int r=0;r<board.size();r++)
        {
            for(int c=0;c<board[0].size();c++)
            {
                if(dfs(board, word, r, c, 0))
                    return true;
            }
        }

        return false;
    }
};