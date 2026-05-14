/*
 PROBLEM 29: LONGEST REPEATING CHARACTER REPLACEMENT

Problem Statement:

You are given a string s consisting of uppercase English letters and an integer k.

You can replace at most k characters in the string with any other character.

Return the length of the longest substring that can be formed where all characters are the same after at most k replacements.

Example 1:

Input:
s = "ABAB", k = 2

Output:
4

Explanation:
Replace both 'A' with 'B' (or vice versa).

Example 2:

Input:
s = "AABABBA", k = 1

Output:
4

Explanation:
Replace one 'A' or 'B' to make "AABA" or "ABBA".

*/




/*
Problem: Longest Repeating Character Replacement

Given a string s and integer k,
find longest substring where you can replace at most k characters
to make all characters same.

Pattern: Sliding Window + Frequency Count
Key Idea:
window size - maxFreq ≤ k
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "AABABBA";
    int k = 1;

    vector<int> freq(26, 0);

    int l = 0, maxFreq = 0, ans = 0;

    for(int r = 0; r < s.size(); r++) {
        freq[s[r] - 'A']++;
        maxFreq = max(maxFreq, freq[s[r] - 'A']);

        while((r - l + 1) - maxFreq > k) {
            freq[s[l] - 'A']--;
            l++;
        }

        ans = max(ans, r - l + 1);
    }

    cout << ans;
}