/*
Problem: Meeting Rooms II

Input:
[[0,30],[5,10],[15,20]]

Output:
2
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> v={{0,30},{5,10},{15,20}};
    sort(v.begin(),v.end());

    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(v[0][1]);

    for(int i=1;i<v.size();i++){
        if(v[i][0]>=pq.top()) pq.pop();
        pq.push(v[i][1]);
    }
    cout<<pq.size();
}