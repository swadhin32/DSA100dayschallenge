/*
🧩 PROBLEM 31: DAILY TEMPERATURES

Problem Statement:

Given an array of integers temperatures where temperatures[i] represents the temperature on day i, return an array answer such that:

👉 answer[i] is the number of days you have to wait after day i to get a warmer temperature.
👉 If there is no future day for which this is possible, keep 0.

Example 1:

Input:
temperatures = [73,74,75,71,69,72,76,73]

Output:
[1,1,4,2,1,1,0,0]

Example 2:

Input:
temperatures = [30,40,50,60]

Output:
[1,1,1,0]

Example 3:

Input:
temperatures = [30,60,90]

Output:
[1,1,0]
*/





/*
Problem: Daily Temperatures

Pattern: Monotonic Stack
Key Idea:
Keep decreasing stack of indices
When current temp > stack top → resolve previous
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> temp = {73,74,75,71,69,72,76,73};
    int n = temp.size();

    vector<int> ans(n, 0);
    stack<int> st; // stores indices

    for(int i = 0; i < n; i++) {
        while(!st.empty() && temp[i] > temp[st.top()]) {
            int idx = st.top();
            st.pop();
            ans[idx] = i - idx;
        }
        st.push(i);
    }

    for(int x : ans) cout << x << " ";
}