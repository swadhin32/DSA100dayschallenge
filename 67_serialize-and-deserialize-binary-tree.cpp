// Serialize and Deserialize Binary Tree
// Pattern: Tree Encoding

// Problem Statement:
// Design an algorithm to:

// Serialize a binary tree into a string
// Deserialize the string back into the original tree

// Serialization means converting the tree into a storable/transmittable format.

// Deserialization means rebuilding the exact same tree from that data.

// Example:

// Input Tree:
// 1
// /
// 2 3
// /
// 4 5

// Serialized Output:
// "1,2,null,null,3,4,null,null,5,null,null"

// Output after Deserialization:
// Original tree restored successfully.

// Core Concepts:
// ✅ DFS Traversal
// ✅ Tree Reconstruction
// ✅ Encoding & Decoding
// ✅ Recursive Parsing

// Main Logic:
// Serialization:

// traverse tree (usually preorder)
// store node values
// store "null" for missing nodes

// Deserialization:

// read values one by one
// rebuild tree recursively in same order

// Important Insight:
// Without storing NULL nodes,
// original tree structure gets lost.

// Example:
// These two trees become ambiguous otherwise:

// 1           1

// /
// 2 2

// ━━━━━━━━━━━━━━━━━━/




























#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    void serializeHelper(TreeNode* root, string& s)
    {
        if(root == NULL)
        {
            s += "null,";
            return;
        }

        s += to_string(root->val) + ",";

        serializeHelper(root->left, s);

        serializeHelper(root->right, s);
    }

    string serialize(TreeNode* root) 
    {
        string s = "";

        serializeHelper(root, s);

        return s;
    }


    
    TreeNode* build(vector<string>& nodes, int& i)
    {
        if(nodes[i] == "null")
        {
            i++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(nodes[i]));

        i++;

        root->left = build(nodes, i);

        root->right = build(nodes, i);

        return root;
    }

    TreeNode* deserialize(string data) 
    {
        vector<string> nodes;

        string temp = "";

        for(char c : data)
        {
            if(c == ',')
            {
                nodes.push_back(temp);
                temp = "";
            }
            else
            {
                temp += c;
            }
        }

        int i = 0;

        return build(nodes, i);
    }
};