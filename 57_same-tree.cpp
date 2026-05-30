// Same Tree
// Pattern: Tree Comparison DFS

// Problem Statement:
// Given the roots of two binary trees p and q, write a function to check if they are the same or not.

// Two binary trees are considered the same if:

// they are structurally identical
// corresponding nodes have the same value

// Example 1:

// Input:
// p = [1,2,3]
// q = [1,2,3]

// Output:
// true

// Example 2:

// Input:
// p = [1,2]
// q = [1,null,2]

// Output:
// false

// Explanation:
// Structure is different.

// Core Concepts:
// ✅ DFS Traversal
// ✅ Recursive Tree Comparison
// ✅ Structural Validation
// ✅ Node-by-node Matching

// Main Logic:
// For every node:

// values must match
// left subtrees must match
// right subtrees must match






















class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p == NULL && q == NULL)
            return true;

        if(p == NULL || q == NULL)
            return false;

        if(p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};