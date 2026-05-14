/*
Problem: Stock Span

Input:
[100,80,60,70,60,75,85]

Output:
[1,1,1,2,1,4,6]
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> price={100,80,60,70,60,75,85};
    stack<int> st;
    vector<int> span(price.size());

    for(int i=0;i<price.size();i++){
        while(!st.empty() && price[st.top()]<=price[i])
            st.pop();

        span[i]=st.empty()?i+1:i-st.top();
        st.push(i);
    }

    for(int x:span) cout<<x<<" ";
}