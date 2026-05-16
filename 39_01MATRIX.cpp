/*PROBLEM 39: 01 MATRIX

Problem Statement:

You are given a binary matrix mat containing only 0 and 1.

For every cell containing 1, find the distance to the nearest 0.

You may move only:

up
down
left
right

Distance between adjacent cells = 1.

Return the distance matrix.

Example 1:

Input:
mat =
[
[0,0,0],
[0,1,0],
[0,0,0]
]

Output:
[
[0,0,0],
[0,1,0],
[0,0,0]
]

Example 2:

Input:
mat =
[
[0,0,0],
[0,1,0],
[1,1,1]
]

Output:
[
[0,0,0],
[0,1,0],
[1,2,1]
]*/





/*
Problem: 01 Matrix

Pattern: Multi-source BFS
Key Idea:
Start BFS from all zeros simultaneously
Spread distances outward
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<vector<int>> mat = {
        {0,0,0},
        {0,1,0},
        {1,1,1}
    };

    int m = mat.size();
    int n = mat[0].size();

    queue<pair<int,int>> q;

    vector<vector<int>> dist(m, vector<int>(n, -1));

    // Push all 0s first
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {

            if(mat[i][j] == 0) {
                q.push({i,j});
                dist[i][j] = 0;
            }
        }
    }

    vector<pair<int,int>> dir = {
        {1,0},{-1,0},{0,1},{0,-1}
    };

    while(!q.empty()) {

        auto [x,y] = q.front();
        q.pop();

        for(auto [dx,dy] : dir) {

            int nx = x + dx;
            int ny = y + dy;

            if(nx>=0 && ny>=0 && nx<m && ny<n && dist[nx][ny]==-1) {

                dist[nx][ny] = dist[x][y] + 1;

                q.push({nx,ny});
            }
        }
    }

    // Print answer
    for(auto row : dist) {
        for(int x : row)
            cout << x << " ";
        cout << endl;
    }
}