// Binary Tree Postorder Traversal
// Pattern: Tree DFS

// Problem Statement:
// Given the root of a binary tree, return the postorder traversal of its nodes’ values.

// Postorder Traversal follows:
// Left → Right → Root

// Example:

// Input:
// 1
// /
// 2 3
// /
// 4 5

// Output:
// [4, 5, 2, 3, 1]

// Explanation:

// Traverse left subtree
// Traverse right subtree
// Visit root at the end

// Core Concepts:
// ✅ DFS Traversal
// ✅ Bottom-up Tree Processing
// ✅ Useful for Tree Deletion & DP on Trees
// ✅ Children processed before parent

// ━━━━━━━━━━━━━━━━━━

// 🌲 Traversal Trinity:

// Preorder → Root Left Right
// Inorder → Left Root Right
// Postorder → Left Right Root

// These three traversals are the heartbeat of tree problems ⚔️










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

    void postorder(TreeNode* root, vector<int>& ans) {

        if(root == NULL)
            return;

        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};