/*
Problem: Merge Intervals

Input:
[[1,3],[2,6],[8,10]]

Output:
[[1,6],[8,10]]
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> v={{1,3},{2,6},{8,10}};
    sort(v.begin(),v.end());

    vector<vector<int>> res;
    res.push_back(v[0]);

    for(int i=1;i<v.size();i++){
        if(v[i][0]<=res.back()[1])
            res.back()[1]=max(res.back()[1],v[i][1]);
        else
            res.push_back(v[i]);
    }

    for(auto x:res)
        cout<<"["<<x[0]<<","<<x[1]<<"] ";
}