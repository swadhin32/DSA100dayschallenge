// Balanced Binary Tree
// Pattern: Height DFS

// Problem Statement:
// Given the root of a binary tree, determine if it is height-balanced.

// A binary tree is balanced if:
// for every node,
// the difference between the heights of left and right subtree is not more than 1.

// Example 1:

// Input:
// 3
// /
// 9 20
// /
// 15 7

// Output:
// true

// Example 2:

// Input:
// 1
// /
// 2
// /
// 3
// /
// 4

// Output:
// false

// Explanation:
// Left subtree becomes too deep compared to right subtree.

// Core Concepts:
// ✅ DFS Traversal
// ✅ Height Calculation
// ✅ Bottom-up Recursion
// ✅ Balance Checking

// Main Logic:
// For every node:

// calculate left height
// calculate right height
// if abs(left - right) > 1 → unbalanced

// Important Insight:
// This problem teaches:
// 👉 “while returning height, also validate condition”

// A very common tree DP pattern.











class Solution {
public:

    int height(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        int leftHeight = height(root->left);

        if(leftHeight == -1)
            return -1;

        int rightHeight = height(root->right);

        if(rightHeight == -1)
            return -1;

        if(abs(leftHeight - rightHeight) > 1)
            return -1;

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) 
    {
        return height(root) != -1;
    }
};