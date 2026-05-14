/*
Problem: Non-overlapping Intervals

Input:
[[1,2],[2,3],[3,4],[1,3]]

Output:
1
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> v={{1,2},{2,3},{3,4},{1,3}};
    sort(v.begin(),v.end(),[](auto&a,auto&b){
        return a[1]<b[1];
    });

    int end=v[0][1],count=0;

    for(int i=1;i<v.size();i++){
        if(v[i][0]<end) count++;
        else end=v[i][1];
    }
    cout<<count;
}