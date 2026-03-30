#include "3StarGraphGenerator.h"
#include <stdexcept>

Graph StarGraphGenerator::generate() const {
    if (n < 2) {
        throw std::invalid_argument("Star graph requires at least 2 vertices");
    }
    Graph g(n);
    for (int i = 1; i < n; ++i) {
        g.addEdge(0, i);
    }
    return g;
}

std::string StarGraphGenerator::name() const {
    return "Star S_" + std::to_string(n);
}