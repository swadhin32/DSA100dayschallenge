/*
Problem: Next Greater Element

Input:
[4,5,2,10]

Output:
[5,10,10,-1]
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={4,5,2,10};
    stack<int> st;
    vector<int> res(arr.size());

    for(int i=arr.size()-1;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i])
            st.pop();
        res[i]=st.empty()?-1:st.top();
        st.push(arr[i]);
    }

    for(int x:res) cout<<x<<" ";
}