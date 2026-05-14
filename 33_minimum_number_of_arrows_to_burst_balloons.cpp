/*
🧩 PROBLEM 33: MINIMUM NUMBER OF ARROWS TO BURST BALLOONS

Problem Statement:

You are given an array points where each element represents a balloon as [start, end].

An arrow can be shot at any point x.
A balloon [start, end] bursts if start ≤ x ≤ end.

Return the minimum number of arrows required to burst all balloons.

Example 1:

Input:
points = [[10,16],[2,8],[1,6],[7,12]]

Output:
2

Example 2:

Input:
points = [[1,2],[3,4],[5,6],[7,8]]

Output:
4
*/



/*
Problem: Minimum Number of Arrows to Burst Balloons

Pattern: Greedy + Sorting
Key Idea:
Sort by end → shoot arrow at earliest end
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};

    sort(points.begin(), points.end(), [](auto &a, auto &b) {
        return a[1] < b[1];
    });

    int arrows = 1;
    int end = points[0][1];

    for(int i = 1; i < points.size(); i++) {
        if(points[i][0] > end) {
            arrows++;
            end = points[i][1];
        }
    }

    cout << arrows;
}