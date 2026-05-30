// Validate Binary Search Tree
// Pattern: BST Validation

// Problem Statement:
// Given the root of a binary tree, determine if it is a valid Binary Search Tree (BST).

// A valid BST follows:

// left subtree values < current node
// right subtree values > current node
// both left and right subtree must also be valid BSTs

// Example 1:

// Input:
// 2
// /
// 1 3

// Output:
// true

// Example 2:

// Input:
// 5
// /
// 1 4
// /
// 3 6

// Output:
// false

// Explanation:
// Node 3 is in the right subtree of 5,
// but 3 < 5,
// which violates BST rules.

// Core Concepts:
// ✅ DFS Traversal
// ✅ Range Validation
// ✅ BST Properties
// ✅ Recursive Constraints

// Main Logic:
// Every node must stay within valid range:
// (minValue < node < maxValue)

// While moving:

// left child gets upper bound
// right child gets lower bound

// Important Insight:
// BST validation is NOT just checking parent-child relation.
// Entire subtree constraints matter.

// ━━━━━━━━━━━━━━━━━━

// ⚔️ BST Upgrade:

// Normal Tree:
// “Visit everything.”

// BST:
// “Use ordering to make smart decisions.”

// That ordering property turns many O(N) problems into near O(log N) traversal paths 🌲🔥




















class Solution {
public:

    bool validate(TreeNode* root, long minVal, long maxVal)
    {
        if(root == NULL)
            return true;

        if(root->val <= minVal || root->val >= maxVal)
            return false;

        return validate(root->left, minVal, root->val) &&
               validate(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) 
    {
        return validate(root, LONG_MIN, LONG_MAX);
    }
};