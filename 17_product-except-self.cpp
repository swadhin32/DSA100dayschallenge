/*
Problem: Product of Array Except Self

Input:
[1,2,3,4]

Output:
[24,12,8,6]
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={1,2,3,4};
    int n=arr.size();
    vector<int> res(n,1);

    int left=1;
    for(int i=0;i<n;i++){
        res[i]=left;
        left*=arr[i];
    }

    int right=1;
    for(int i=n-1;i>=0;i--){
        res[i]*=right;
        right*=arr[i];
    }

    for(int x:res) cout<<x<<" ";
}