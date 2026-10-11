/*
99. Dijkstra’s Shortest Path Algorithm
    Pattern: Graph + Heap

Problem Statement:

Given a weighted graph with V vertices and E edges, along with a source vertex src, find the shortest distance from the source vertex to every other vertex in the graph.

All edge weights are non-negative.

If a vertex cannot be reached from the source, its distance should be considered infinity (or represented by an appropriate value such as -1 in the output).

Example:

Input:

V = 5

Edges = [
[0,1,4],
[0,2,1],
[2,1,2],
[1,3,1],
[2,3,5],
[3,4,3]
]

src = 0

Output:
[0,3,1,4,7]

Explanation:

The shortest distances from vertex 0 are:

* Distance to vertex 0 = 0
* Distance to vertex 1 = 3 (0 → 2 → 1)
* Distance to vertex 2 = 1 (0 → 2)
* Distance to vertex 3 = 4 (0 → 2 → 1 → 3)
* Distance to vertex 4 = 7 (0 → 2 → 1 → 3 → 4)

Core Concepts:
✅ Weighted Graphs
✅ Greedy Algorithm
✅ Min Heap / Priority Queue
✅ Shortest Path
✅ Relaxation of Edges

Main Logic:

1. Initialize the source distance to 0 and all other distances to infinity.
2. Insert the source vertex into a min heap.
3. Extract the vertex with the smallest known distance.
4. Explore its neighboring vertices.
5. If a shorter path is found, update the distance and push the updated pair into the heap.
6. Continue until the heap becomes empty.

Important Insight:

Dijkstra’s algorithm always processes the vertex with the smallest currently known distance first.

Important constraint: Standard Dijkstra’s algorithm requires non-negative edge weights.
*/

public int[] Dijkstra(
    int V,
    List<List<(int node, int weight)>> adj,
    int src)
{
    int[] dist = Enumerable.Repeat(int.MaxValue, V).ToArray();

    PriorityQueue<int, int> minHeap =
        new PriorityQueue<int, int>();

    dist[src] = 0;
    minHeap.Enqueue(src, 0);

    while (minHeap.Count > 0)
    {
        minHeap.TryDequeue(out int u, out int d);

        // Ignore outdated heap entries
        if (d != dist[u])
            continue;

        foreach (var edge in adj[u])
        {
            int v = edge.node;
            int weight = edge.weight;

            if (d + weight < dist[v])
            {
                dist[v] = d + weight;
                minHeap.Enqueue(v, dist[v]);
            }
        }
    }

    return dist;
}