#include "12WheelGraphGenerator.h"
#include <stdexcept>

Graph WheelGraphGenerator::generate() const {
    if (n < 4) {
        throw std::invalid_argument("Wheel requires n >= 4");
    }
    Graph g(n);

    // Центр (0) соединён со всеми на ободе
    for (int i = 1; i < n; ++i) {
        g.addEdge(0, i);
    }

    // Обод — цикл из вершин 1..n-1
    for (int i = 1; i < n; ++i) {
        int next = (i == n - 1) ? 1 : i + 1;
        g.addEdge(i, next);
    }

    return g;
}

std::string WheelGraphGenerator::name() const {
    return "Wheel W_" + std::to_string(n);
}