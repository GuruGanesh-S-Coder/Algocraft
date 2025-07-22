#include "Graph.hpp"

Graph::Graph(int vertices) {
    V = vertices;
    adj.resize(V);
}

void Graph::addEdge(int u, int v, int weight) {
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight}); // Undirected
}

void Graph::dijkstra(int src) {
    std::vector<int> dist(V, std::numeric_limits<int>::max());
    dist[src] = 0;

    using pii = std::pair<int, int>;
    std::priority_queue<pii, std::vector<pii>, std::greater<>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    std::cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; ++i) {
        std::cout << "To " << i << ": " << dist[i] << "\n";
    }
}

void Graph::printGraph() {
    for (int i = 0; i < V; ++i) {
        std::cout << i << ": ";
        for (auto& neighbor : adj[i]) {
            std::cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        std::cout << "\n";
    }
}
