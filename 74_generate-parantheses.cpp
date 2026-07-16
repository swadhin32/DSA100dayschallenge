/* 74. Generate Parentheses
    Pattern: Backtracking + Stack

Problem Statement:
Given n pairs of parentheses,
write a function to generate all combinations of well-formed parentheses.

Example:

Input:
n = 3

Output:
[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]

Explanation:
Only valid balanced parentheses combinations are allowed.

Examples like:
"(()"
or
")(("
are invalid.

Core Concepts:
✅ Backtracking
✅ Recursive String Building
✅ Constraint-based Exploration
✅ Stack-like Balancing Logic

Main Logic:
At every step:

* add '(' if open count < n
* add ')' only if close count < open count

This guarantees valid formation.

Important Insight:
Backtracking becomes extremely powerful when:
👉 rules prune invalid paths early

Instead of generating all possibilities,
we intelligently avoid bad states 🧠🔥

━━━━━━━━━━━━━━━━━━

⚔️ Backtracking Evolution:

Subsets:
“Take or skip.”

Permutations:
“Arrange choices.”

Generate Parentheses:
“Explore only VALID states.”

This is where recursion starts feeling like strategy instead of brute force 🎯🔥 */



class Solution {
public:

    vector<string> ans;

    void backtrack(string current,
                   int open,
                   int close,
                   int n)
    {
        if(current.length() == 2 * n)
        {
            ans.push_back(current);
            return;
        }

        if(open < n)
        {
            backtrack(current + "(",
                      open + 1,
                      close,
                      n);
        }

        if(close < open)
        {
            backtrack(current + ")",
                      open,
                      close + 1,
                      n);
        }
    }

    vector<string> generateParenthesis(int n) 
    {
        backtrack("", 0, 0, n);

        return ans;
    }
};