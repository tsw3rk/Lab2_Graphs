#include "2BipartiteGraphGenerator.h"
#include <stdexcept>

Graph BipartiteGraphGenerator::generate() const {
    if (n <= 0 || m <= 0) {
        throw std::invalid_argument("n and m must be positive");
    }
    Graph g(n + m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            g.addEdge(i, n + j);
        }
    }
    return g;
}

std::string BipartiteGraphGenerator::name() const {
    return "Bipartite K_" + std::to_string(n) + "," + std::to_string(m);
}