/*
Problem: Find Maximum Element in Array

Given:
arr = [1,5,2,9,3]

Output:
9
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1,5,2,9,3};
    int mx = INT_MIN;

    for(int x : arr)
        mx = max(mx, x);

    cout << mx;
}