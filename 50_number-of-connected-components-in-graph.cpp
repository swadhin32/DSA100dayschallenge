/*
Problem Statement:
Given:

number of vertices n
list of edges

Return the number of connected components in the graph.

Example:

Input:

n = 5

edges = [[0,1],[1,2],[3,4]]

Output:
2

Explanation:

Component 1:
0 — 1 — 2

Component 2:
3 — 4

*/







class Solution {
public:

    void dfs(int node,
             vector<vector<int>>& adj,
             vector<int>& visited)
    {
        visited[node] = 1;

        for(int neighbor : adj[node])
        {
            if(!visited[neighbor])
            {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int countComponents(int n,
                        vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);

            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);

        int components = 0;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                components++;

                dfs(i, adj, visited);
            }
        }

        return components;
    }
};