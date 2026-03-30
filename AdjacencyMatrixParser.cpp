#include "AdjacencyMatrixParser.h"
#include <fstream>
#include <stdexcept>

Graph AdjacencyMatrixParser::parse(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + filename);
    }

    int n;
    file >> n;

    if (n <= 0) {
        throw std::runtime_error("Number of vertices must be positive.");
    }

    Graph graph(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int value;
            file >> value;

            if (value != 0 && value != 1) {
                throw std::runtime_error("Matrix should contain only 0 or 1.");
            }

            if (value == 1) {
                graph.addEdge(i, j);
            }
        }
    }

    return graph;
}