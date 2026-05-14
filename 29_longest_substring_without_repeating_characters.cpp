/*PROBLEM 29: LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS

Problem Statement:

Given a string s, find the length of the longest substring without repeating characters.

A substring must be continuous.

Example 1:

Input:
s = "abcabcbb"

Output:
3

Explanation:
"abc" is the longest substring without repeating characters.

Example 2:

Input:
s = "bbbbb"

Output:
1

Explanation:
"b" is the longest substring.

Example 3:

Input:
s = "pwwkew"

Output:
3

Explanation:
"wke" is the longest substring. 
*/




/*
Problem: Longest Substring Without Repeating Characters

Input:
s = "abcabcbb"

Output:
3

Pattern: Sliding Window + HashMap
Key Idea: Expand window, shrink when duplicate found
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "abcabcbb";

    unordered_map<char,int> mp;
    int l = 0, ans = 0;

    for(int r = 0; r < s.size(); r++) {
        mp[s[r]]++;

        while(mp[s[r]] > 1) {
            mp[s[l]]--;
            l++;
        }

        ans = max(ans, r - l + 1);
    }

    cout << ans;
}