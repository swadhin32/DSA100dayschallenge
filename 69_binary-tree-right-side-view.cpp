/* 
69. Binary Tree Right Side View
    Pattern: Level Order BFS

Problem Statement:
Given the root of a binary tree,
imagine yourself standing on the right side of it.
Return the values of the nodes you can see ordered from top to bottom.

Example:

Input:
1
/ 
2   3
\    
5    4

Output:
[1, 3, 4]

Explanation:
From the right side:

* level 1 → 1 visible
* level 2 → 3 visible
* level 3 → 4 visible

Core Concepts:
✅ Breadth First Search (BFS)
✅ Level Order Traversal
✅ Queue Processing
✅ Last Node of Each Level

Main Logic:

* perform level order traversal
* for every level,
    store the last node processed

Alternative DFS Idea:
Traverse:
Root → Right → Left

First node visited at every depth becomes visible node.

Important Insight:
Many “view problems” in trees are actually:
👉 “level-based observation problems”

 */


 class Solution {
public:

    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;

        if(root == NULL)
            return ans;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty())
        {
            int size = q.size();

            for(int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if(i == size - 1)
                {
                    ans.push_back(node->val);
                }

                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }
        }

        return ans;
    }
};