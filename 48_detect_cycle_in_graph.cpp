/*
Problem Statement:
Given an undirected graph, determine whether it contains a cycle.

Example:

Vertices = 5

Edges:
0-1
1-2
2-3
3-4
4-1

Output:
true

Core Idea:

Use DFS traversal
Track parent node
If visited neighbor exists and it is NOT parent,
cycle exists

Pattern:
Graph DFS + Parent Tracking
*/
















class Solution {
public:

    bool dfs(int node,
             int parent,
             vector<int> adj[],
             vector<int>& visited)
    {
        visited[node] = 1;

        for(int neighbor : adj[node])
        {
            if(!visited[neighbor])
            {
                if(dfs(neighbor, node, adj, visited))
                {
                    return true;
                }
            }
            else if(neighbor != parent)
            {
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {

        vector<int> visited(V, 0);

        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                if(dfs(i, -1, adj, visited))
                {
                    return true;
                }
            }
        }

        return false;
    }
};