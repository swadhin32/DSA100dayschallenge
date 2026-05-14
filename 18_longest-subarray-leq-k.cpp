/*
Problem: Longest Subarray with Sum ≤ K

Input:
[1,2,1,0,1,1,0], K = 4

Output:
5
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={1,2,1,0,1,1,0};
    int K=4;
    int l=0,sum=0,ans=0;

    for(int r=0;r<arr.size();r++){
        sum+=arr[r];
        while(sum>K){
            sum-=arr[l++];
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
}