/*
Problem: Subarray Sum = K (Positive Numbers)

Find continuous subarray with sum = K.

Input:
arr = [1,2,3,7,5], K = 12

Output:
Indices of subarray (1,3)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1,2,3,7,5};
    int K = 12;

    int l=0,sum=0;
    for(int r=0;r<arr.size();r++){
        sum+=arr[r];
        while(sum>K){
            sum-=arr[l++];
        }
        if(sum==K){
            cout<<l<<" "<<r;
            break;
        }
    }
}