/*
Problem: Two Sum

Given:
nums = [2,7,11,15], target = 9

Return indices:
[0,1]
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {2,7,11,15};
    int target = 9;
    unordered_map<int,int> mp;

    for(int i = 0; i < arr.size(); i++) {
        if(mp.count(target - arr[i])) {
            cout << mp[target-arr[i]] << " " << i;
            break;
        }
        mp[arr[i]] = i;
    }
}