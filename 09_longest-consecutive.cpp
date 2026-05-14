/*
Problem: Longest Consecutive Sequence

Input:
[100,4,200,1,3,2]

Output:
4 (sequence: 1,2,3,4)
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={100,4,200,1,3,2};
    unordered_set<int> st(arr.begin(),arr.end());
    int ans=0;

    for(int num:arr){
        if(!st.count(num-1)){
            int cur=num,len=1;
            while(st.count(cur+1)){
                cur++; len++;
            }
            ans=max(ans,len);
        }
    }
    cout<<ans;
}