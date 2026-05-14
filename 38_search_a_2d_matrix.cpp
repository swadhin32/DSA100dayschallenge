/*
🧩 PROBLEM 38: SEARCH A 2D MATRIX

Problem Statement:

You are given an m x n integer matrix with these properties:

Each row is sorted in ascending order
First integer of each row is greater than last integer of previous row

Given an integer target, return true if target exists in matrix, else false.

You must solve it in O(log(m*n)) time.

Example 1:

Input:
matrix =
[
[1,3,5,7],
[10,11,16,20],
[23,30,34,60]
]

target = 3

Output:
true

Example 2:

Input:
target = 13

Output:
false
*/








/*
Problem: Search a 2D Matrix

Pattern: Binary Search
Key Idea:
Treat matrix as sorted 1D array
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };

    int target = 3;

    int m = matrix.size();
    int n = matrix[0].size();

    int l = 0, r = m*n - 1;

    while(l <= r) {
        int mid = (l + r) / 2;

        int row = mid / n;
        int col = mid % n;

        int val = matrix[row][col];

        if(val == target) {
            cout << "true";
            return 0;
        }

        if(val < target)
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << "false";
}