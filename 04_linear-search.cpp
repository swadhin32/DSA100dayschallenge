/*
Problem: Linear Search

Find index of target in array.

Input:
arr = [1,2,3,4], target = 3

Output:
2
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1,2,3,4};
    int target = 3;

    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == target) {
            cout << i;
            break;
        }
    }
}