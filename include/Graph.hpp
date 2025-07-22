#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

class Graph {
private:
    int V;
    std::vector<std::vector<std::pair<int, int>>> adj;

public:
    Graph(int vertices);
    void addEdge(int u, int v, int weight);
    void dijkstra(int src);
    void printGraph();
};

#endif
