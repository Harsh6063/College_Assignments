#include <iostream>
#include <vector>
#include <queue>
#include <stack>

class graph {
    int nodes;
    std::vector<std::vector<int>> adj;

public:
    graph(int n) : nodes(n), adj(n) {}

    void add_edge(int from, int to) {
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    void BFS(int root_node) {
        std::vector<bool> visited(nodes, false);
        std::queue<int> q;

        q.push(root_node);
        visited[root_node] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            std::cout << current << " ";

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    void DFS(int root_node) {
        std::vector<bool> visited(nodes, false);
        std::stack<int> stk;

        stk.push(root_node);
        visited[root_node] = true;

        while (!stk.empty()) {
            int curr = stk.top();
            stk.pop();

            std::cout << curr << " ";

            for (int neighbor : adj[curr]) {
                if (!visited[neighbor]) {
                    stk.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
};

int main() {
    int vertices, edges;
    std::cout << "Enter the number of vertices: ";
    std::cin >> vertices;
    std::cout << "Enter the number of edges: ";
    std::cin >> edges;

    graph g(vertices);
    std::cout << "Enter edges (source destination):" << std::endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        std::cin >> u >> v;
        g.add_edge(u, v);
    }

    std::cout << "BFS traversal: ";
    g.BFS(0);
    std::cout << "\nDFS traversal: ";
    g.DFS(0);

    return 0;
}
