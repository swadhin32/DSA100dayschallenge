// Diameter of Binary Tree
// Pattern: Tree DP

// Problem Statement:
// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is:
// the length of the longest path between any two nodes in the tree.

// This path may or may not pass through the root.

// Example:

// Input:
// 1
// /
// 2 3
// /
// 4 5

// Output:
// 3

// Explanation:
// Longest path:
// 4 → 2 → 1 → 3
// Number of edges = 3

// Core Concepts:
// ✅ DFS Traversal
// ✅ Tree Height Calculation
// ✅ Tree Dynamic Programming
// ✅ Longest Path Problems

// Main Logic:
// At every node:
// Diameter through current node =
// left height + right height

// Then keep updating global maximum.

// Important Insight:
// For trees,
// many “path problems”
// are secretly:
// 👉 “combine left subtree + right subtree”

// ━━━━━━━━━━━━━━━━━━

// ⚔️ Evolution of Tree Thinking:

// Traversal → Comparison → Transformation → Path Optimization

// Now trees are becoming true recursive battlefields 🌲🔥

























class Solution {
public:

    int diameter = 0;

    int height(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        int leftHeight = height(root->left);

        int rightHeight = height(root->right);

        diameter = max(diameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) 
    {
        height(root);

        return diameter;
    }
};