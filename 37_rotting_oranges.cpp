/*🧩 PROBLEM 37: ROTTING ORANGES

Problem Statement:

You are given an m x n grid where:

0 = empty cell
1 = fresh orange 🍊
2 = rotten orange 🤢

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes needed so that no fresh orange remains.

If impossible, return -1.

Example 1:

Input:
grid =
[
[2,1,1],
[1,1,0],
[0,1,1]
]

Output:
4

Example 2:

Input:
grid =
[
[2,1,1],
[0,1,1],
[1,0,1]
]

Output:
-1

Explanation:
Bottom-left orange can never rot.

Constraints:

1 ≤ m, n ≤ 10

Your Task:

grid =
[
[2,1,1],
[1,1,1],
[0,1,2]
]

Find minimum minutes.
*/





/*
Problem: Rotting Oranges

Pattern: Multi-source BFS
Key Idea:
Start BFS from all rotten oranges simultaneously
Each level = 1 minute
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    int m = grid.size(), n = grid[0].size();

    queue<pair<int,int>> q;
    int fresh = 0, minutes = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 2)
                q.push({i,j});
            else if(grid[i][j] == 1)
                fresh++;
        }
    }

    vector<pair<int,int>> dir = {
        {1,0},{-1,0},{0,1},{0,-1}
    };

    while(!q.empty() && fresh > 0) {
        int sz = q.size();
        minutes++;

        while(sz--) {
            auto [x,y] = q.front();
            q.pop();

            for(auto [dx,dy] : dir) {
                int nx = x + dx;
                int ny = y + dy;

                if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==1) {
                    grid[nx][ny] = 2;
                    fresh--;
                    q.push({nx,ny});
                }
            }
        }
    }

    cout << (fresh == 0 ? minutes : -1);
}