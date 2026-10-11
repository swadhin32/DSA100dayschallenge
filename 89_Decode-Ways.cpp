/*
89. Decode Ways
    Pattern: DP on Strings

Problem Statement:
A message containing letters from A-Z is encoded using the following mapping:

1 → A
2 → B
…
26 → Z

Given a string s containing only digits, return the total number of ways to decode it.

Note:

* ‘0’ cannot be decoded by itself.
* Digits can be decoded individually or in pairs if they form a valid number between 10 and 26.

Example 1:

Input:
s = “12”

Output:
2

Explanation:
“12” can be decoded as:

* “AB” (1,2)
* “L” (12)

Example 2:

Input:
s = “226”

Output:
3

Explanation:
Possible decodings:

* “BZ” (2,26)
* “VF” (22,6)
* “BBF” (2,2,6)

Example 3:

Input:
s = “06”

Output:
0

Explanation:
A string starting with ‘0’ cannot be decoded.

Core Concepts:
✅ Dynamic Programming
✅ String Processing
✅ Recursion + Memoization
✅ State Transition

Main Logic:
For each position:

* Decode one digit (if valid)
* Decode two digits (if they form 10–26)

Transition:

dp[i] =
ways using one digit +
ways using two digits

Important Insight:
At every character,
you decide whether to take:
👉 one digit
or
👉 two digits

This makes it a classic DP decision problem.
*/



class Solution {
public:
    int numDecodings(string s)
    {
        int n = s.size();

        vector<int> dp(n + 1, 0);

        dp[n] = 1;

        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == '0')
            {
                dp[i] = 0;
                continue;
            }

            dp[i] = dp[i + 1];

            if(i + 1 < n)
            {
                int num =
                    (s[i]-'0') * 10 +
                    (s[i+1]-'0');

                if(num >= 10 && num <= 26)
                {
                    dp[i] += dp[i + 2];
                }
            }
        }

        return dp[0];
    }
};