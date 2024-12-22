#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Disjoint Set (Union-Find) class
class DisjointSet {
public:
    vector<int> parent, rank;

    // Constructor to initialize parent and rank
    DisjointSet(int vertices) {
        parent.resize(vertices);
        rank.resize(vertices, 0);
        for (int i = 0; i < vertices; i++) {
            parent[i] = i;
        }
    }

    // Find function with path compression
    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]); // Path compression
        }
        return parent[node];
    }

    // Union function with union by rank
    void union_sets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            // Union by rank
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

// Graph class representing a graph
class Graph {
public:
    int vertices;
    vector<vector<int>> edges;

    // Constructor
    Graph(int v) : vertices(v) {}

    // Function to add an edge to the graph
    void add_edge(int src, int dest, int weight) {
        edges.push_back({src, dest, weight});
    }

    // Kruskal's algorithm to find the Minimum Spanning Tree (MST)
    pair<vector<vector<int>>, int> kruskal() {
        // Sort edges by weight
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2]; // Compare the weights (a[2] and b[2])
        });

        DisjointSet ds(vertices);
        vector<vector<int>> mst;
        int total_weight = 0;

        // Process each edge
        for (const auto& edge : edges) {
            int src = edge[0];
            int dest = edge[1];
            int weight = edge[2];

            // If src and dest are in different sets, add the edge to MST
            if (ds.find(src) != ds.find(dest)) {
                mst.push_back(edge);
                total_weight += weight;
                ds.union_sets(src, dest);
            }
        }

        return {mst, total_weight};
    }
};

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    Graph g(v);

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges as 'source destination weight':\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.add_edge(u, v, w);
    }

    auto result = g.kruskal();
    vector<vector<int>> mst = result.first;
    int total_weight = result.second;

    cout << "\n------------------------\n";
    cout << "Edges in the MST:\n";
    for (const auto& edge : mst) {
        cout << edge[0] << " -> " << edge[1] << " : " << edge[2] << "\n";
    }
    cout << "------------------------\n";
    cout << "\n------------------------\n";
    cout << "Total weight of MST: " << total_weight << "\n";
    cout << "------------------------\n";

    return 0;
}
