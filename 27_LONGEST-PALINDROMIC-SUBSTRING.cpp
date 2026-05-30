/*
🧩 PROBLEM 27: LONGEST PALINDROMIC SUBSTRING

Problem Statement:

Given a string s, return the longest substring of s which is a palindrome.

A palindrome is a string that reads the same forward and backward.

Example 1:

Input:
s = "babad"

Output:
"bab"

Explanation:
"aba" is also a valid answer.

Example 2:

Input:
s = "cbbd"

Output:
"bb"

*/

/*
Problem: Longest Palindromic Substring

Given a string s,
find the longest substring which is a palindrome.

Example:
Input: "babad"
Output: "bab" or "aba"

Pattern: Expand Around Center
Key Idea:
- Treat each index as center
- Expand left and right
*/

#include <bits/stdc++.h>
using namespace std;

string expand(string s, int l, int r) {
    while(l >= 0 && r < s.size() && s[l] == s[r]) {
        l--;
        r++;
    }
    return s.substr(l+1, r-l-1);
}

int main() {
    string s = "babad";
    string ans = "";

    for(int i = 0; i < s.size(); i++) {
        string odd = expand(s, i, i);
        string even = expand(s, i, i+1);

        if(odd.size() > ans.size()) ans = odd;
        if(even.size() > ans.size()) ans = even;
    }

    cout << ans;
    cout << "done";
}