// Lowest Common Ancestor of a Binary Search Tree
// Pattern: BST Properties

// Problem Statement:
// Given a Binary Search Tree (BST) and two nodes p and q,
// find their Lowest Common Ancestor (LCA).

// The Lowest Common Ancestor is the lowest node in the tree that has both p and q as descendants.

// BST Property:

// Left subtree values < Root
// Right subtree values > Root

// Example:

// Input:
// 6
// /
// 2 8
// / \ /
// 0 4 7 9
// /
// 3 5

// p = 2
// q = 8

// Output:
// 6

// Example 2:

// p = 2
// q = 4

// Output:
// 2

// Explanation:
// Node 2 itself becomes the ancestor.

// Core Concepts:
// ✅ BST Traversal
// ✅ Decision Making using BST Property
// ✅ Divide & Conquer
// ✅ Recursive Search

// Main Logic:

// if both nodes are smaller → move left
// if both nodes are larger → move right
// otherwise current node is LCA

// Important Insight:
// BST lets us avoid traversing entire tree.
// Search direction becomes deterministic.





















class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }

        if(p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};