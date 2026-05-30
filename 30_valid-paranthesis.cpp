/*
🧩 PROBLEM 30: VALID PARENTHESES

Problem Statement:

Given a string s containing just the characters:

( ) { } [ ]

Determine if the input string is valid.

A string is valid if:

Open brackets are closed by the same type
Open brackets are closed in the correct order

Example 1:

Input:
s = "()"

Output:
true

Example 2:

Input:
s = "()[]{}"

Output:
true

Example 3:

Input:
s = "(]"

Output:
false

Example 4:

Input:
s = "([)]"

Output:
false
*/








/*
Problem: Valid Parentheses

Pattern: Stack
Key Idea:
Push opening brackets
Pop when matching closing bracket appears
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "{[()]}";
    stack<char> st;

    for(char c : s) {
        if(c == '(' || c == '{' || c == '[')
            st.push(c);
        else {
            if(st.empty()) {
                cout << "false";
                return 0;
            }

            char top = st.top();
            st.pop();

            if((c == ')' && top != '(') ||
               (c == '}' && top != '{') ||
               (c == ']' && top != '[')) {
                cout << "false";
                return 0;
            }
        }
    }

    cout << (st.empty() ? "true" : "false");
}