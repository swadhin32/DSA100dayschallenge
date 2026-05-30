/*PROBLEM 40: ASTEROID COLLISION

Problem Statement:

You are given an integer array asteroids.

Each asteroid moves at the same speed.

Positive value → moving right
Negative value → moving left

When two asteroids collide:

Smaller asteroid explodes
If equal size → both explode
Larger asteroid survives

Return the final state of asteroids after all collisions.

Example 1:

Input:
[5,10,-5]

Output:
[5,10]

Explanation:
10 destroys -5

Example 2:

Input:
[8,-8]

Output:
[]

Explanation:
Both explode.

Example 3:

Input:
[10,2,-5]

Output:
[10]
*/

















/*
Problem: Asteroid Collision

Pattern: Stack
Key Idea:
Collision possible only when:
stack top positive
current asteroid negative
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> ast = {5,10,-5};

    stack<int> st;

    for(int x : ast) {

        bool destroyed = false;

        while(!st.empty() && st.top() > 0 && x < 0) {

            // top smaller -> explode
            if(abs(st.top()) < abs(x)) {
                st.pop();
                continue;
            }

            // equal size -> both explode
            else if(abs(st.top()) == abs(x)) {
                st.pop();
            }

            destroyed = true;
            break;
        }

        if(!destroyed)
            st.push(x);
    }

    vector<int> ans;

    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    for(int x : ans)
        cout << x << " ";
}