/*
Problem: Minimum Window Substring

Given strings s and t, return smallest substring of s containing all chars of t.

Input:
s = "ADOBECODEBANC", t = "ABC"

Output:
"BANC"
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s="ADOBECODEBANC", t="ABC";
    unordered_map<char,int> mp;
    for(char c:t) mp[c]++;

    int l=0,count=t.size(),minLen=INT_MAX,start=0;

    for(int r=0;r<s.size();r++){
        if(mp[s[r]]>0) count--;
        mp[s[r]]--;

        while(count==0){
            if(r-l+1<minLen){
                minLen=r-l+1;
                start=l;
            }
            mp[s[l]]++;
            if(mp[s[l]]>0) count++;
            l++;
        }
    }

    cout<<s.substr(start,minLen);
}