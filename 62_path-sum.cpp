// Path Sum
// Pattern: Tree DFS

// Problem Statement:
// Given the root of a binary tree and an integer targetSum,
// return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

// A leaf node is a node with no children.

// Example:

// Input:
// targetSum = 22

//     5
//    / \
//   4   8
//  /   / \
// 11  13  4

// /
// 7 2

// Output:
// true

// Explanation:
// Path:
// 5 → 4 → 11 → 2

// Sum:
// 5 + 4 + 11 + 2 = 22

// Core Concepts:
// ✅ DFS Traversal
// ✅ Recursive Path Tracking
// ✅ Root-to-Leaf Problems
// ✅ Running Sum Technique

// Main Logic:
// At every node:

// subtract node value from target
// recursively check children
// if leaf reached and remaining target becomes 0 → found path

// Important Insight:
// Tree path problems often use:
// 👉 “carry information downward”

// Examples:

// current sum
// maximum value
// path string
// path length

// ━━━━━━━━━━━━━━━━━━

// 🌲 Tree Pattern Expansion:

// Height Problems → Balance Problems
// Path Problems → Carry state downward
// Diameter Problems → Combine child results upward

// This is where recursive intuition starts becoming dangerous ⚔️🔥









class Solution {
public:

    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(root == NULL)
            return false;

        targetSum -= root->val;

        if(root->left == NULL && root->right == NULL)
        {
            return targetSum == 0;
        }

        return hasPathSum(root->left, targetSum) ||
               hasPathSum(root->right, targetSum);
    }
};