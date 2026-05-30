// Binary Tree Inorder Traversal
// Pattern: Tree DFS

// Problem Statement:
// Given the root of a binary tree, return the inorder traversal of its nodes’ values.

// Inorder Traversal follows:
// Left → Root → Right

// Example:

// Input:
// 1
// /
// 2 3
// /
// 4 5

// Output:
// [4, 2, 5, 1, 3]

// Core Concepts:
// ✅ Tree Traversal
// ✅ DFS Recursion
// ✅ Recursive Call Stack
// ✅ Foundation for BST problems

// ━━━━━━━━━━━━━━━━━━
















#include <vector>
#include <cstddef>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:

    void inorder(TreeNode* root, vector<int>& ans) {

        if(root == NULL)
            return;

        // LEFT
        inorder(root->left, ans);

        // ROOT
        ans.push_back(root->val);

        // RIGHT
        inorder(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;

        inorder(root, ans);

        return ans;
    }
};