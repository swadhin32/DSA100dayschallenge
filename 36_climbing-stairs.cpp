/*
🧩 PROBLEM 36: CLIMBING STAIRS

Problem Statement:

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb:

1 step
or 2 steps

Return the number of distinct ways to reach the top.

Example 1:

Input:
n = 2

Output:
2

Explanation:
1+1, 2

Example 2:

Input:
n = 3

Output:
3

Explanation:
1+1+1, 1+2, 2+1
*/










/*
Problem: Climbing Stairs

Pattern: Dynamic Programming (Fibonacci)
Key Idea:
ways(n) = ways(n-1) + ways(n-2)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;

    if(n <= 2) {
        cout << n;
        return 0;
    }

    int prev2 = 1, prev1 = 2, curr;

    for(int i = 3; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    cout << prev1;
}