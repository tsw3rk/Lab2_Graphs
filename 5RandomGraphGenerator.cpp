#include "5RandomGraphGenerator.h"
#include <stdexcept>
#include <random>

Graph RandomGraphGenerator::generate() const {
    if (n < 0) throw std::invalid_argument("n must be >= 0");
    if (p < 0.0 || p > 1.0) throw std::invalid_argument("p must be in [0,1]");
    Graph g(n);

    std::mt19937 gen(seed);
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (dis(gen) < p) {
                g.addEdge(i, j);
            }
        }
    }
    return g;
}

std::string RandomGraphGenerator::name() const {
    return "Random G(" + std::to_string(n) + ", " + std::to_string(static_cast<int>(p * 100)) + "%)";
}