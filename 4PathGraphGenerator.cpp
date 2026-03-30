#include "4PathGraphGenerator.h"
#include <stdexcept>

Graph PathGraphGenerator::generate() const {
    if (n < 1) {
        throw std::invalid_argument("Path graph requires n >= 1");
    }
    Graph g(n);
    for (int i = 0; i < n - 1; ++i) {
        g.addEdge(i, i + 1);
    }
    return g;
}

std::string PathGraphGenerator::name() const {
    return "Path P_" + std::to_string(n);
}