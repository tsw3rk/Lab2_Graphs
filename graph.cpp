#include "Graph.h"
#include <stdexcept> // для throw

Graph::Graph(int n) : vertexCount(n), adjacencyList(n) {}

int Graph::getVertexCount() const {
    return vertexCount;
}

void Graph::addEdge(int u, int v) {
    if (u < 0 || u >= vertexCount || v < 0 || v >= vertexCount) {
        throw std::out_of_range("Invalid vertex index");
    }
    adjacencyList[u].insert(v);
    adjacencyList[v].insert(u); // Так как граф неориентированный
}

bool Graph::hasEdge(int u, int v) const {
    if (u < 0 || u >= vertexCount || v < 0 || v >= vertexCount) {
        return false; // или throw std::out_of_range
    }
    return adjacencyList[u].count(v) > 0;
}

std::vector<int> Graph::getNeighbors(int u) const {
    if (u < 0 || u >= vertexCount) {
        throw std::out_of_range("Invalid vertex index");
    }
    return std::vector<int>(adjacencyList[u].begin(), adjacencyList[u].end());
}