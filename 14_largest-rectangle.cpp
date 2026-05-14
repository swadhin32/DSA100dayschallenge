/*
Problem: Largest Rectangle in Histogram

Input:
[2,1,5,6,2,3]

Output:
10
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> h={2,1,5,6,2,3};
    stack<int> st;
    int maxArea=0,n=h.size();

    for(int i=0;i<=n;i++){
        int cur=(i==n)?0:h[i];
        while(!st.empty() && cur<h[st.top()]){
            int height=h[st.top()];
            st.pop();
            int left=st.empty()?-1:st.top();
            int width=i-left-1;
            maxArea=max(maxArea,height*width);
        }
        st.push(i);
    }
    cout<<maxArea;
}