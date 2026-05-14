/*
Problem: Count Subarrays Divisible by K

Input:
[4,5,0,-2,-3,1], K = 5

Output:
7
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={4,5,0,-2,-3,1};
    int K=5;

    unordered_map<int,int> mp;
    mp[0]=1;

    int sum=0,ans=0;

    for(int x:arr){
        sum+=x;
        int rem=sum%K;
        if(rem<0) rem+=K;

        ans+=mp[rem];
        mp[rem]++;
    }
    cout<<ans;
}