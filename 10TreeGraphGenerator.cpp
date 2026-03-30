#include "10TreeGraphGenerator.h"
#include <stdexcept>
#include <random>

Graph TreeGraphGenerator::generate() const {
    if (n < 1) {
        throw std::invalid_argument("Tree requires n >= 1");
    }
    Graph g(n);

    if (n == 1) return g; // дерево из 1 вершины

    std::mt19937 gen(seed);
    for (int i = 1; i < n; ++i) {
        std::uniform_int_distribution<> dis(0, i - 1);
        int parent = dis(gen);
        g.addEdge(parent, i);
    }
    return g;
}

std::string TreeGraphGenerator::name() const {
    return "Tree T_" + std::to_string(n);
}