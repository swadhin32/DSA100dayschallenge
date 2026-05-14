/*
Problem: Top K Frequent Elements

Input:
nums = [1,1,1,2,2,3], k = 2

Output:
[1,2]
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums={1,1,1,2,2,3};
    int k=2;

    unordered_map<int,int> mp;
    for(int x:nums) mp[x]++;

    priority_queue<pair<int,int>> pq;
    for(auto it:mp)
        pq.push({it.second,it.first});

    while(k--){
        cout<<pq.top().second<<" ";
        pq.pop();
    }
}