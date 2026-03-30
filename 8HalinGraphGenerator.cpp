#include "8HalinGraphGenerator.h"
#include <stdexcept>

Graph HalinGraphGenerator::generate() const {
    if (m < 3) {
        throw std::invalid_argument("Halin graph requires at least 3 leaves (m >= 3)");
    }
    int n = m + 1; // центр + m листьев
    Graph g(n);

    // 1. Звезда: центр (0) соединён со всеми листьями (1..m)
    for (int i = 1; i <= m; ++i) {
        g.addEdge(0, i);
    }

    // 2. Обводим листья циклом: 1-2-3-...-m-1
    for (int i = 1; i <= m; ++i) {
        int next = (i == m) ? 1 : i + 1;
        g.addEdge(i, next);
    }

    return g;
}

std::string HalinGraphGenerator::name() const {
    return "Halin (star-based, " + std::to_string(m) + " leaves)";
}