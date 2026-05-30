// Construct Binary Tree from Preorder and Inorder Traversal
// Pattern: Tree Construction

// Problem Statement:
// Given two integer arrays:

// preorder
// inorder

// construct and return the binary tree.

// Rules:

// Preorder = Root → Left → Right
// Inorder = Left → Root → Right

// Example:

// Input:
// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]

// Output Tree:
// 3
// /
// 9 20
// /
// 15 7

// Explanation:

// first element of preorder is always root
// inorder splits left and right subtrees

// Core Concepts:
// ✅ Recursive Tree Construction
// ✅ DFS Divide & Conquer
// ✅ Traversal Logic
// ✅ HashMap Optimization

// Main Logic:

// preorder gives current root
// find root position in inorder
// left side becomes left subtree
// right side becomes right subtree
// recursively build both sides

// Important Insight:
// Traversal arrays secretly contain
// the complete blueprint of the tree 🧩🌲

// ━━━━━━━━━━━━━━━━━━

// ⚔️ Massive Tree Milestone:

// Traversal → Validation → Searching → Construction

// You are now entering advanced recursive visualization territory.
// At this stage,
// good tree solvers start “seeing recursion” before coding it 🔥



#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    unordered_map<int,int> mp;

    int preorderIndex = 0;

    TreeNode* build(vector<int>& preorder,
                    vector<int>& inorder,
                    int left,
                    int right)
    {
        if(left > right)
            return NULL;

        int rootValue = preorder[preorderIndex++];

        TreeNode* root = new TreeNode(rootValue);

        int inorderIndex = mp[rootValue];

        root->left = build(preorder,
                           inorder,
                           left,
                           inorderIndex - 1);

        root->right = build(preorder,
                            inorder,
                            inorderIndex + 1,
                            right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) 
    {
        for(int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }

        return build(preorder,
                     inorder,
                     0,
                     inorder.size() - 1);
    }
};