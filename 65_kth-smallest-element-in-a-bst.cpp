// Kth Smallest Element in a BST
// Pattern: Inorder Traversal

// Problem Statement:
// Given the root of a Binary Search Tree (BST) and an integer k,
// return the kth smallest value of all the nodes in the tree.

// Important BST Property:
// Inorder traversal of a BST gives nodes in sorted order.

// Example:

// Input:
// 3
// /
// 1 4

// 2

// k = 1

// Output:
// 1

// Example 2:

// Input:
// 5
// /
// 3 6
// /
// 2 4
// /
// 1

// k = 3

// Output:
// 3

// Core Concepts:
// ✅ Inorder Traversal
// ✅ BST Properties
// ✅ DFS Traversal
// ✅ Sorted Order Extraction

// Main Logic:

// perform inorder traversal
// count nodes while traversing
// when count becomes k → answer found

// Important Insight:
// BST + Inorder =
// automatic sorted sequence 🌲

// ━━━━━━━━━━━━━━━━━━

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    int count = 0;
    int ans = 0;

    void inorder(TreeNode* root, int k)
    {
        if(root == nullptr)
            return;

        inorder(root->left, k);

        count++;

        if(count == k)
        {
            ans = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) 
    {
        inorder(root, k);

        return ans;
    }
};