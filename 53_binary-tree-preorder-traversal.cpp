// Binary Tree Preorder Traversal
// Pattern: Tree DFS

// Problem Statement:
// Given the root of a binary tree, return the preorder traversal of its nodes’ values.

// Preorder Traversal follows:
// Root → Left → Right

// Example:

// Input:
// 1
// /
// 2 3
// /
// 4 5

// Output:
// [1, 2, 4, 5, 3]

// Explanation:

// Visit root first
// Then traverse left subtree
// Then traverse right subtree

// Core Concepts:
// ✅ DFS Traversal
// ✅ Recursive Tree Processing
// ✅ Root-first traversal
// ✅ Useful in Tree Construction problems

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

    void preorder(TreeNode* root, vector<int>& ans) {

        if(root == NULL)
            return;

        // ROOT
        ans.push_back(root->val);

        // LEFT
        preorder(root->left, ans);

        // RIGHT
        preorder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ans;

        preorder(root, ans);

        return ans;
    }
};