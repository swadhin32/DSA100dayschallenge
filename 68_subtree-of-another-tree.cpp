/*
Subtree of Another Tree
Pattern: Tree Matching

Problem Statement:
Given the roots of two binary trees root and subRoot,
return true if there is a subtree of root
with the same structure and node values as subRoot.

A subtree is a node in the tree along with all of its descendants.

Example:

Input:

root:
3
/
4 5
/
1 2

subRoot:
4
/
1 2

Output:
true

Example 2:

root:
3
/
4 5
/
1 2
/
0

subRoot:
4
/
1 2

Output:
false

Explanation:
Extra node 0 changes the structure.

Core Concepts:
✅ DFS Traversal
✅ Tree Comparison
✅ Recursive Matching
✅ Subtree Detection

Main Logic:
For every node in root:

check if trees match completely
if not, recursively search left and right subtree

Important Insight:
This problem combines:
👉 “tree traversal”
+
👉 “same tree comparison”

It is basically:
Same Tree problem hidden inside another tree 🌲🧠

━━━━━━━━━━━━━━━━━━

⚔️ Tree Power Level Rising:

Now trees are no longer just traversed.

They are:

encoded
reconstructed
searched inside other trees
structurally compared

Recursive thinking is becoming your default operating system 🔥
*/



using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    vector<int> arr = {9,2,3,9,5,2};
    unordered_map<int, int> mp;

    for (int i : arr) {
        if (mp[i]) {
            cout << i << endl;
        }
        mp[i] = 1;
    }

    return 0;
}
