#include <iostream>
#include "Graph.h"

int main() {
    // Create a graph with 5 nodes (0 to 4)
    Graph g(5);

    // Add edges to the graph
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 5);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 4, 2);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 2, 6);

    // Print the graph
    g.printGraph();

    // Run Dijkstra's algorithm to find the shortest path from node 0 to node 3
    g.dijkstra(0, 3);

    return 0;
}
