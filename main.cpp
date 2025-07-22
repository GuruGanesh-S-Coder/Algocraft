#include <iostream>
#include "Graph.hpp"
#include "HashTable.hpp"

int main() {
    Graph graph(5);
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 1);
    graph.addEdge(2, 3, 7);
    graph.addEdge(3, 4, 1);

    graph.printGraph();
    graph.dijkstra(0);

    HashTable ht;
    ht.insert("lang", "C++");
    ht.insert("project", "AlgoCraft");

    std::cout << "Get 'lang': " << ht.get("lang") << std::endl;
    std::cout << "Get 'project': " << ht.get("project") << std::endl;

    return 0;
}
