/*
Problem: Longest Subarray Sum = K

Input:
[1,-1,5,-2,3], K = 3

Output:
4
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={1,-1,5,-2,3};
    int K=3;

    unordered_map<int,int> mp;
    int sum=0,ans=0;

    for(int i=0;i<arr.size();i++){
        sum+=arr[i];

        if(sum==K) ans=i+1;

        if(mp.count(sum-K))
            ans=max(ans,i-mp[sum-K]);

        if(!mp.count(sum))
            mp[sum]=i;
    }
    cout<<ans;
}