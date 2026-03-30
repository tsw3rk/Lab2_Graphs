#include "11CycleGraphGenerator.h"
#include <stdexcept>

Graph CycleGraphGenerator::generate() const {
    if (n < 3) {
        throw std::invalid_argument("Cycle requires n >= 3");
    }
    Graph g(n);
    for (int i = 0; i < n; ++i) {
        g.addEdge(i, (i + 1) % n);
    }
    return g;
}

std::string CycleGraphGenerator::name() const {
    return "Cycle C_" + std::to_string(n);
}