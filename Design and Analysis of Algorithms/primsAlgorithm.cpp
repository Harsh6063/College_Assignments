#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V), adj(V, vector<int>(V, 0)) {}

    void addEdge(int u, int v, int weight) {
        adj[u][v] = weight;
        adj[v][u] = weight; // For undirected graph
    }

    int minKey(vector<int>& key, vector<bool>& mst) {
        int minKey = INT_MAX, minKey_index = -1;
        for (int v = 0; v < V; ++v) {
            if (!mst[v] && key[v] < minKey) {
                minKey = key[v];
                minKey_index = v;
            }
        }
        return minKey_index;
    }

    void primMST() {
        vector<int> parent(V, -1), key(V, INT_MAX);
        vector<bool> mst(V, false);

        key[0] = 0; // Start with the first vertex

        for (int i = 0; i < V - 1; ++i) {
            int u = minKey(key, mst);
            mst[u] = true;

            for (int v = 0; v < V; ++v) {
                if (adj[u][v] && !mst[v] && adj[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = adj[u][v];
                }
            }
        }

        cout << "Edges of Minimum Spanning Tree:" << endl;
        for (int i = 1; i < V; ++i) {
            cout << "Edge: " << parent[i] << " - " << i << ", Weight: " << adj[i][parent[i]] << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph g(V);
    cout << "Enter edges (source, destination, weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    g.primMST();
    return 0;
}
