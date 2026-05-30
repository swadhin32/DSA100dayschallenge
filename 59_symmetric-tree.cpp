// Symmetric Tree
// Pattern: Mirror DFS

// Problem Statement:
// Given the root of a binary tree, check whether it is a mirror of itself (symmetric around its center).

// A tree is symmetric if:

// left subtree is a mirror reflection of right subtree

// Example 1:

// Input:
// 1
// /
// 2 2
// / \ /
// 3 4 4 3

// Output:
// true

// Example 2:

// Input:
// 1
// /
// 2 2
// \
// 3 3

// Output:
// false

// Explanation:
// Structure is not mirrored properly.

// Core Concepts:
// ✅ DFS Traversal
// ✅ Mirror Comparison
// ✅ Recursive Tree Matching
// ✅ Symmetry Checking

// Main Logic:
// Compare:

// left.left with right.right
// left.right with right.left

// Mirror relationship is the key idea.




























class Solution {
public:

    bool isMirror(TreeNode* left, TreeNode* right)
    {
        if(left == NULL && right == NULL)
            return true;

        if(left == NULL || right == NULL)
            return false;

        if(left->val != right->val)
            return false;

        return isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) 
    {
        return isMirror(root->left, root->right);
    }
};