/*
100. Network Delay Time
    Pattern: Shortest Path Graph + Dijkstra

Problem Statement:

You are given a network of n nodes labeled from 1 to n, and a list of directed edges times, where times[i] = [u, v, w] represents a signal travelling from node u to node v in w units of time.

You are also given an integer k, representing the node from which the signal is sent.

Return the minimum time required for all nodes to receive the signal.

If it is impossible for all nodes to receive the signal, return -1.

Example 1:

Input:

times = [
[2,1,1],
[2,3,1],
[3,4,1]
]

n = 4
k = 2

Output:
2

Explanation:

The signal starts at node 2.

* Node 1 receives the signal after 1 unit.
* Node 3 receives the signal after 1 unit.
* Node 4 receives the signal after 2 units.

The signal reaches every node in 2 units of time.

Example 2:

Input:

times = [
[1,2,1]
]

n = 2
k = 1

Output:
1

Example 3:

Input:

times = [
[1,2,1]
]

n = 2
k = 2

Output:
-1

Explanation:

Node 1 cannot be reached from node 2, so the signal cannot reach every node.

Core Concepts:
✅ Dijkstra’s Algorithm
✅ Directed Weighted Graph
✅ Min Heap / Priority Queue
✅ Shortest Distance Calculation
✅ Graph Reachability

Main Logic:

1. Build an adjacency list from the given edges.
2. Run Dijkstra’s algorithm starting from node k.
3. Calculate the shortest distance from k to every node.
4. If any node remains unreachable, return -1.
5. Otherwise, return the maximum shortest distance among all nodes.

Important Insight:

The answer is:

Maximum of all shortest-path distances from the source.

Why maximum?

Because the network delay is determined by the time taken for the signal to reach the farthest node along its shortest path.

━━━━━━━━━━━━━━━━━━

🏆 100-PROBLEM DSA SHEET COMPLETED!

Your journey covered:

✅ Arrays & Hashing
✅ Two Pointers & Sliding Window
✅ Stack & Queue
✅ Binary Search
✅ Linked Lists
✅ Trees & BST
✅ Backtracking
✅ Dynamic Programming
✅ Greedy Algorithms
✅ Heaps & Priority Queues
✅ Tries
✅ Union Find (DSU)
✅ Graphs & Shortest Paths

🎯 Final takeaway:

Dijkstra’s Algorithm → Finds shortest distances from one source.

Network Delay Time → Uses those shortest distances to determine when the entire network receives the signal.

100 problems. One complete syllabus. One big milestone. 🔥🏁

Now the real mission begins: revising these patterns, solving them independently, and becoming interview-ready. 💪
*/

public int NetworkDelayTime(
    int[][] times,
    int n,
    int k)
{
    List<(int node, int weight)>[] adj =
        new List<(int, int)>[n + 1];

    for (int i = 1; i <= n; i++)
        adj[i] = new List<(int, int)>();

    foreach (int[] edge in times)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u].Add((v, w));
    }

    int[] dist = Enumerable.Repeat(int.MaxValue, n + 1).ToArray();

    PriorityQueue<int, int> minHeap =
        new PriorityQueue<int, int>();

    dist[k] = 0;
    minHeap.Enqueue(k, 0);

    while (minHeap.Count > 0)
    {
        minHeap.TryDequeue(out int u, out int d);

        if (d != dist[u])
            continue;

        foreach (var edge in adj[u])
        {
            int v = edge.node;
            int weight = edge.weight;
            int newDist = d + weight;

            if (newDist < dist[v])
            {
                dist[v] = newDist;
                minHeap.Enqueue(v, newDist);
            }
        }
    }

    int answer = 0;

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == int.MaxValue)
            return -1;

        answer = Math.Max(answer, dist[i]);
    }

    return answer;
}