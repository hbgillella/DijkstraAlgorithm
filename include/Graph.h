#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <limits>
#include <algorithm>  // For reverse

class Graph {
public:
    Graph(int nodes);  // Constructor to initialize the graph with a certain number of nodes
    void addEdge(int u, int v, int weight);  // Adds an edge between nodes u and v with a given weight
    void dijkstra(int start, int end);  // Dijkstra's algorithm to find the shortest path
    void printGraph();  // Prints the adjacency matrix of the graph

private:
    std::vector<std::vector<std::pair<int, int>>> adjMatrix;  // Adjacency matrix (list of pairs)
    int nodes;  // Number of nodes in the graph
};

#endif // GRAPH_H

