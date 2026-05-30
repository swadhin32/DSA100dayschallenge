/*
Problem 41: Number of Islands
Problem Statement

You are given a 2D grid containing '1' (land) and '0' (water).

Return the number of islands.

An island is formed by connecting adjacent lands horizontally or vertically.

Example

Input:

1 1 0 0
1 0 0 1
0 0 1 1
0 0 0 0

Output:

2

Intuition

This is a DFS/BFS connected components problem.

Whenever we find an unvisited '1':

we found a new island
start DFS/BFS from there
mark all connected land cells visited

Continue scanning the grid.*/

















class Solution {
public:

    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if(r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0')
            return;

        grid[r][c] = '0';

        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

    int numIslands(vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        int count = 0;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == '1')
                {
                    count++;

                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }
};