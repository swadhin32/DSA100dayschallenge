/*
97. Word Break
    Pattern: DP + Trie

Problem Statement:
Given a string s and a dictionary of strings wordDict,
return true if s can be segmented into one or more dictionary words.

The same word in the dictionary may be used multiple times.

Example 1:

Input:
s = “leetcode”
wordDict = [“leet”,“code”]

Output:
true

Explanation:
“leetcode” can be segmented as:

“leet” + “code”

Example 2:

Input:
s = “applepenapple”
wordDict = [“apple”,“pen”]

Output:
true

Explanation:
“applepenapple” can be segmented as:

“apple” + “pen” + “apple”

Example 3:

Input:
s = “catsandog”
wordDict = [“cats”,“dog”,“sand”,“and”,“cat”]

Output:
false

Explanation:
The string cannot be completely segmented using the given dictionary.

Core Concepts:
✅ Dynamic Programming
✅ Trie
✅ String Processing
✅ Prefix Matching
✅ Memoization

Main Logic:
Let dp[i] represent whether the substring from index i to the end can be successfully segmented.

At every position:

* Try possible dictionary words
* If a word matches the current substring:
    * recursively/iteratively check the remaining string
* Store already calculated states to avoid repeated work.

Important Insight:
The main question is:

👉 “Can I split the string at this position so that BOTH parts can be formed from dictionary words?”

This creates a classic DP decision pattern.
*/



//  https://youtube.com/shorts/o3UszpsC1LU?si=azizw6Mz4_lGJcNQ

public bool WordBreak(string s, IList<string> wordDict)
{
    HashSet<string> words = new HashSet<string>(wordDict);

    int n = s.Length;

    bool[] dp = new bool[n + 1];

    dp[0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] && words.Contains(s.Substring(j, i - j)))
            {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}