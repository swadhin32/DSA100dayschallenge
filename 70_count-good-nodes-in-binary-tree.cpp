/* 70. Count Good Nodes in Binary Tree
    Pattern: DFS + Path Maximum

Problem Statement:
Given a binary tree root,
a node X is called “good”
if in the path from root to X,
there are no nodes with a value greater than X.

Return the number of good nodes.

Example:

Input:
3
/ 
1   4
/   / 
3   1   5

Output:
4

Explanation:
Good nodes are:

* 3 (root)
* 4
* 5
* left side 3

Node 1 is not good because 3 exists before it.

Core Concepts:
✅ DFS Traversal
✅ Path Tracking
✅ Carry State Downward
✅ Running Maximum

Main Logic:
While traversing:

* keep track of maximum value seen so far
* if current node >= maxSeen → good node
* update maxSeen for children

Important Insight:
This is a classic:
👉 “carry information from parent to child”

Very important recursive pattern.

━━━━━━━━━━━━━━━━━━

🌲 Tree Saga Completed (70 Problems) 🔥

You have now covered:
✅ Traversals
✅ BFS & DFS
✅ Tree Construction
✅ Tree Comparison
✅ Path Problems
✅ BST Logic
✅ Tree DP
✅ Recursive State Passing

Next kingdom ahead:
⚔️ BACKTRACKING ⚔️

Where recursion stops behaving like traversal…
and starts behaving like exploration 🧩 */



class Solution {
public:

    int count = 0;

    void dfs(TreeNode* root, int maxSeen)
    {
        if(root == NULL)
            return;

        if(root->val >= maxSeen)
        {
            count++;
        }

        maxSeen = max(maxSeen, root->val);

        dfs(root->left, maxSeen);

        dfs(root->right, maxSeen);
    }

    int goodNodes(TreeNode* root) 
    {
        dfs(root, root->val);

        return count;
    }
};