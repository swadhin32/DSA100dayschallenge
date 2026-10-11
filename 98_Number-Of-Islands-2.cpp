/*
98. Number of Islands II
    Pattern: Union Find (DSU)

Problem Statement:
You are given an initially empty m × n grid where every cell is water.

You are given a list of positions where land is added one by one.

After each land addition, return the number of islands in the grid.

An island is a group of horizontally or vertically connected land cells.

Example:

Input:
m = 3
n = 3

positions = [
[0,0],
[0,1],
[1,2],
[2,1]
]

Output:
[1,1,2,3]

Explanation:

After adding [0,0]:

1 0 0
0 0 0
0 0 0

Number of islands = 1

After adding [0,1]:

1 1 0
0 0 0
0 0 0

The two land cells connect.

Number of islands = 1

After adding [1,2]:

1 1 0
0 0 1
0 0 0

Number of islands = 2

After adding [2,1]:

1 1 0
0 0 1
0 1 0

Number of islands = 3

Core Concepts:
✅ Union Find / DSU
✅ Path Compression
✅ Union by Rank / Size
✅ Dynamic Connectivity
✅ Grid Graph

Main Logic:
Initially:
👉 Every new land cell creates one new island.

For every newly added land:

1. Mark it as land.
2. Increase island count by 1.
3. Check its four neighboring cells.
4. If a neighboring cell is already land:
    * Find their DSU parents.
    * If they belong to different components, union them.
    * Decrease island count by 1.

Important Insight:
The key idea is:

New land → islands + 1

Connecting two different islands → islands - 1

DSU lets us efficiently determine whether two cells already belong to the same connected component.

━━━━━━━━━━━━━━━━━━

⚡ Final Stretch:

Word Break → DP + String Decisions

Number of Islands II → Dynamic Connectivity + DSU
 🔥*/

 public class DSU
{
    private int[] parent;
    private int[] size;

    public DSU(int n)
    {
        parent = new int[n];
        size = new int[n];

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    public int Find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = Find(parent[x]);
        }

        return parent[x];
    }

    public bool Union(int a, int b)
    {
        int rootA = Find(a);
        int rootB = Find(b);

        if (rootA == rootB)
            return false;

        if (size[rootA] < size[rootB])
        {
            int temp = rootA;
            rootA = rootB;
            rootB = temp;
        }

        parent[rootB] = rootA;
        size[rootA] += size[rootB];

        return true;
    }
}



// Now the actual solution for the Number of Islands II problem using the DSU class defined above.

public IList<int> NumIslands2(
    int m,
    int n,
    int[][] positions)
{
    DSU dsu = new DSU(m * n);

    bool[] land = new bool[m * n];

    List<int> result = new List<int>();

    int islands = 0;

    int[][] directions =
    {
        new[] { 1, 0 },
        new[] { -1, 0 },
        new[] { 0, 1 },
        new[] { 0, -1 }
    };

    foreach (int[] position in positions)
    {
        int row = position[0];
        int col = position[1];

        int current = row * n + col;

        // Already land
        if (land[current])
        {
            result.Add(islands);
            continue;
        }

        // New land creates a new island
        land[current] = true;
        islands++;

        foreach (int[] dir in directions)
        {
            int nr = row + dir[0];
            int nc = col + dir[1];

            // Outside grid
            if (nr < 0 || nr >= m ||
                nc < 0 || nc >= n)
            {
                continue;
            }

            int neighbor = nr * n + nc;

            // Neighbor must be land
            if (!land[neighbor])
                continue;

            // If two different islands merge
            if (dsu.Union(current, neighbor))
            {
                islands--;
            }
        }

        result.Add(islands);
    }

    return result;
}