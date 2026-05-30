/*
🧩 PROBLEM 35: NUMBER OF ISLANDS

Problem Statement:

You are given a 2D grid of size m x n containing '1' (land) and '0' (water).

Return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.

Example 1:

Input:
grid =
[
["1","1","0","0","0"],
["1","1","0","0","0"],
["0","0","1","0","0"],
["0","0","0","1","1"]
]

Output:
3

Example 2:

Input:
grid =
[
["1","1","1"],
["0","1","0"],
["1","1","1"]
]

Output:
1
*/





/*
Problem: Number of Islands

Pattern: DFS / BFS (Graph traversal)
Key Idea:
Visit each land and mark connected land as visited
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& grid, int i, int j) {
    int m = grid.size(), n = grid[0].size();

    if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0')
        return;

    grid[i][j] = '0'; // mark visited

    dfs(grid, i+1, j);
    dfs(grid, i-1, j);
    dfs(grid, i, j+1);
    dfs(grid, i, j-1);
}

int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    int count = 0;

    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j] == '1') {
                dfs(grid, i, j);
                count++;
            }
        }
    }

    cout << count;
}