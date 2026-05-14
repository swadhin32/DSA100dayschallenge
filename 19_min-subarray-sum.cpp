/*
Problem: Minimum Size Subarray Sum ≥ K

Input:
[2,3,1,2,4,3], K = 7

Output:
2
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={2,3,1,2,4,3};
    int K=7;
    int l=0,sum=0,ans=INT_MAX;

    for(int r=0;r<arr.size();r++){
        sum+=arr[r];
        while(sum>=K){
            ans=min(ans,r-l+1);
            sum-=arr[l++];
        }
    }
    cout<<ans;
}