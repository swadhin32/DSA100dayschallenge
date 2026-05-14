/*
Problem: Reverse an Array

Input:
[1,2,3,4]

Output:
[4,3,2,1]
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1,2,3,4};
    int l = 0, r = arr.size()-1;

    while(l < r) {
        swap(arr[l], arr[r]);
        l++; r--;
    }

    for(int x : arr) cout << x << " ";
}