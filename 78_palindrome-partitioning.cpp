/* 78. Palindrome Partitioning
    Pattern: Backtracking + Strings

Problem Statement:
Given a string s,
partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitionings.

A palindrome is a string that reads the same forward and backward.

Example:

Input:
s = “aab”

Output:
[
[“a”,“a”,“b”],
[“aa”,“b”]
]

Explanation:
Both partitions contain only palindromic substrings.

Valid:
“a” | “a” | “b”
“aa” | “b”

Invalid:
“a” | “ab”
because “ab” is not a palindrome.

Core Concepts:
✅ Backtracking
✅ String Processing
✅ Partitioning Problems
✅ Palindrome Checking

Main Logic:
At every position:

* try all possible substring cuts
* if substring is palindrome:
    * choose it
    * recursively process remaining string
* backtrack afterward

Important Insight:
This is a classic:
👉 “Generate all valid partitions”

Pattern:
Choose a cut → Validate → Recurse

━━━━━━━━━━━━━━━━━━

⚔️ Backtracking Mastery Growing:

Subsets → Include / Exclude
Permutations → Arrange Elements
Parentheses → Generate Valid States
Word Search → Explore Grid Paths
N Queens → Constraint Solving
Phone Combinations → Expand Choices
Palindrome Partitioning → Generate Valid Partitions

You’re now solving problems where recursion actively constructs answers instead of merely traversing data structures 🔥🧩 */







class Solution {
public:

    vector<vector<string>> ans;

    bool isPalindrome(string s,
                      int left,
                      int right)
    {
        while(left < right)
        {
            if(s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    void backtrack(string& s,
                   int start,
                   vector<string>& current)
    {
        if(start == s.size())
        {
            ans.push_back(current);
            return;
        }

        for(int end = start;
            end < s.size();
            end++)
        {
            if(isPalindrome(s,start,end))
            {
                current.push_back(
                    s.substr(
                        start,
                        end - start + 1
                    )
                );

                backtrack(
                    s,
                    end + 1,
                    current
                );

                current.pop_back();
            }
        }
    }

    vector<vector<string>>
    partition(string s)
    {
        vector<string> current;

        backtrack(s,0,current);

        return ans;
    }
};