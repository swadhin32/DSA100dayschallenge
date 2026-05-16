/*
Problem Statement:
There are numCourses courses labeled from 0 to numCourses - 1.

You are given prerequisites where:

[a, b]

means:
to take course a, you must first complete course b.

Return true if it is possible to finish all courses.

Return false if impossible.

Example 1:

Input:
numCourses = 2

prerequisites = [[1,0]]

Output:
true

Explanation:
Take course 0 first, then course 1.

Example 2:

Input:
numCourses = 2

prerequisites = [[1,0],[0,1]]

Output:
false
*/













class Solution {
public:

    bool dfs(int node,
             vector<vector<int>>& adj,
             vector<int>& visited,
             vector<int>& pathVisited)
    {
        visited[node] = 1;

        pathVisited[node] = 1;

        for(int neighbor : adj[node])
        {
            if(!visited[neighbor])
            {
                if(dfs(neighbor, adj, visited, pathVisited))
                {
                    return true;
                }
            }
            else if(pathVisited[neighbor])
            {
                return true;
            }
        }

        pathVisited[node] = 0;

        return false;
    }

    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for(auto edge : prerequisites)
        {
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(numCourses, 0);

        vector<int> pathVisited(numCourses, 0);

        for(int i = 0; i < numCourses; i++)
        {
            if(!visited[i])
            {
                if(dfs(i, adj, visited, pathVisited))
                {
                    return false;
                }
            }
        }

        return true;
    }
};