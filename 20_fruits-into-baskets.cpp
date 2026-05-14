/*
Problem: Fruits into Baskets

Input:
[1,2,3,2,2]

Output:
4
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={1,2,3,2,2};
    unordered_map<int,int> mp;
    int l=0,ans=0;

    for(int r=0;r<arr.size();r++){
        mp[arr[r]]++;

        while(mp.size()>2){
            mp[arr[l]]--;
            if(mp[arr[l]]==0) mp.erase(arr[l]);
            l++;
        }

        ans=max(ans,r-l+1);
    }
    cout<<ans;
}