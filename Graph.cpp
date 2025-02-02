#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <limits>
#include <algorithm>
#include "Graph.h"

Graph::Graph(int nodes) {
    this->nodes = nodes;
    adjMatrix.resize(nodes);  // Resize the adjacency matrix to the given number of nodes
}

void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u].push_back({v, weight});
    adjMatrix[v].push_back({u, weight});  // Assuming undirected graph
}

void Graph::dijkstra(int start, int end) {
    std::unordered_map<int, int> dist;  // Distance from start node
    std::unordered_map<int, int> parent;  // To track the path
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    // Initialize all distances to infinity
    for (int i = 0; i < nodes; i++) {
        dist[i] = std::numeric_limits<int>::max();
    }

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int currNode = pq.top().second;
        pq.pop();

        for (auto neighbor : adjMatrix[currNode]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;

            if (dist[currNode] + weight < dist[nextNode]) {
                dist[nextNode] = dist[currNode] + weight;
                parent[nextNode] = currNode;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    std::cout << "The cost of the shortest path is: " << dist[end] << std::endl;

    // Reconstruct the path
    std::vector<int> path;
    for (int at = end; at != start; at = parent[at]) {
        path.push_back(at);
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());

    std::cout << "The path of the lowest cost is: ";
    for (int node : path) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
}

void Graph::printGraph() {
    for (int i = 0; i < nodes; i++) {
        std::cout << "Node " << i << ": ";
        for (auto edge : adjMatrix[i]) {
            std::cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        std::cout << std::endl;
    }
}
