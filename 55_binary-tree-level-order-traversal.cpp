// Binary Tree Level Order Traversal
// Pattern: Tree BFS

// Problem Statement:
// Given the root of a binary tree, return the level order traversal of its nodes’ values.

// (Level by level traversal from left to right)

// Example:

// Input:
// 3
// /
// 9 20
// /
// 15 7

// Output:
// [
// [3],
// [9,20],
// [15,7]
// ]

// Explanation:

// Traverse tree level by level
// Nodes in same depth are grouped together

// Core Concepts:
// ✅ Breadth First Search (BFS)
// ✅ Queue Data Structure
// ✅ Level-wise Traversal
// ✅ Multi-level Processing

// Important Idea:
// Queue controls the traversal flow.
// Every iteration processes one full level.

// ━━━━━━━━━━━━━━━━━━











class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;

        if(root == NULL)
            return ans;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty())
        {
            int size = q.size();

            vector<int> level;

            for(int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};