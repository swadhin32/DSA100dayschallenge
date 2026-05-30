// Clone Graph
// Pattern: Graph + HashMap + DFS/BFS

// Problem Statement:
// Given a reference of a node in a connected undirected graph, return a deep copy (clone) of the graph.

// Each node in the graph contains:

// an integer value val
// a list of its neighbors

// A deep copy means:

// every node must be newly created
// connections between nodes should remain exactly same
// no original node should be reused

// Example:

// Input Graph:
// 1 -- 2
// | |
// 4 -- 3

// Output:
// Return cloned graph with same structure.

// Core Concepts:
// ✅ Graph Traversal
// ✅ DFS/BFS
// ✅ HashMap for visited/cloned nodes
// ✅ Handling cycles in graph
// ━━━━━━━━━━━━━━━━━━