/* 77. Letter Combinations of a Phone Number
    Pattern: Backtracking

Problem Statement:
Given a string containing digits from 2-9 inclusive,
return all possible letter combinations that the number could represent.

Mapping follows the traditional telephone keypad:

2 → abc
3 → def
4 → ghi
5 → jkl
6 → mno
7 → pqrs
8 → tuv
9 → wxyz

Return the answer in any order.

Example:

Input:
digits = “23”

Output:
[
“ad”,“ae”,“af”,
“bd”,“be”,“bf”,
“cd”,“ce”,“cf”
]

Explanation:

* Digit 2 can be a, b, c
* Digit 3 can be d, e, f
* Generate every possible combination

Core Concepts:
✅ Backtracking
✅ Recursive String Building
✅ Choice Expansion
✅ Cartesian Product Generation

Main Logic:
For each digit:

* choose one corresponding letter
* recursively process next digit
* backtrack after returning

Important Insight:
Each digit creates multiple branches.
Backtracking explores all possible paths through those branches. */




class Solution {
public:

    vector<string> ans;

    vector<string> mapping =
    {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    void backtrack(string& digits,
                   int index,
                   string current)
    {
        if(index == digits.size())
        {
            ans.push_back(current);
            return;
        }

        string letters =
            mapping[digits[index] - '0'];

        for(char ch : letters)
        {
            backtrack(
                digits,
                index + 1,
                current + ch
            );
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if(digits.empty())
            return {};

        backtrack(digits, 0, "");

        return ans;
    }
};