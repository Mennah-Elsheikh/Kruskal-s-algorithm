# Kruskal's Algorithm Implementation in C++

This repository contains an implementation of Kruskal's algorithm in C++ to find the Minimum Spanning Tree (MST) of a connected, undirected graph. The algorithm uses a Disjoint Set (Union-Find) data structure to efficiently manage the merging of sets and to detect cycles in the graph.

## Algorithm Overview

Kruskal's algorithm is a greedy algorithm that finds the Minimum Spanning Tree (MST) of a graph. It works by sorting all the edges in increasing order of their weights and then adding the edges one by one to the MST. If adding an edge creates a cycle, it is discarded. The algorithm uses the Disjoint Set data structure to efficiently check if two vertices are in the same set (i.e., if adding the edge would create a cycle).

## Key Components

### Disjoint Set (Union-Find):
- **Manages disjoint sets** and supports efficient union and find operations.
- **Path Compression**: Optimizes the find operation to flatten the structure of the tree.
- **Union by Rank**: Ensures the smaller tree is attached to the larger tree to maintain a balanced tree.

### Graph:
- **Contains vertices and edges.**
- **Add Edge**: Adds an edge with a source, destination, and weight.
- **Kruskal's Algorithm**: Sorts the edges by weight and iterates through them, adding edges to the MST if they don’t form a cycle.

## How to Run

1. Clone or download the repository.
2. Compile the C++ code using any C++ compiler (e.g., `g++`, Visual Studio, etc.).
3. Run the program. The program will prompt you to input the number of vertices and edges, followed by the edges in the form `source destination weight`.
4. The program will output the edges in the MST along with the total weight.

## Example Input

```
Enter number of vertices: 4
Enter number of edges: 5
Enter edges as 'source destination weight':
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
```

## Example Output

```
------------------------
Edges in the MST:
2 -> 3 : 4
0 -> 3 : 5
0 -> 1 : 10
------------------------

------------------------
Total weight of MST: 19
------------------------
```

## Time Complexity

- **Best case**: O(E log E)
- **Average case**: O(E log E)
- **Worst case**: O(E log E)

Where:
- `E` is the number of edges in the graph.

## Space Complexity

O(V + E) where `V` is the number of vertices and `E` is the number of edges. This is the space used to store the graph and the disjoint set.

## Notes

- Kruskal’s algorithm requires a connected graph for a valid Minimum Spanning Tree.
- This implementation uses path compression and union by rank to optimize the performance of the disjoint set operations.
- The edges are sorted by weight before processing them, which makes this algorithm efficient for graphs with fewer edges.

## Conclusion

Kruskal's algorithm is an efficient, greedy algorithm for finding the Minimum Spanning Tree of a graph. It is widely used in network design, such as connecting computers in a network with minimum cable length, and in other applications where a minimal connecting structure is required.
