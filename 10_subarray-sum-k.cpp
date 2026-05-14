/*
Problem: Count Subarrays with Sum = K

Input:
[1,-1,5,-2,3], K = 3

Output:
3
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={1,-1,5,-2,3};
    int K=3;

    unordered_map<int,int> mp;
    mp[0]=1;

    int sum=0,count=0;

    for(int x:arr){
        sum+=x;
        if(mp.count(sum-K))
            count+=mp[sum-K];
        mp[sum]++;
    }
    cout<<count;
}