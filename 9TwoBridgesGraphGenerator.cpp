#include "9TwoBridgesGraphGenerator.h"
#include <stdexcept>

Graph TwoBridgesGraphGenerator::generate() const {
    if (n < 6) {
        throw std::invalid_argument("2-Bridges requires n >= 6");
    }
    Graph g(n);

    // Первый цикл из 3 вершин: 0-1-2-0
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);

    // Второй цикл из 3 вершин: 3-4-5-3
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 3);

    // 2 моста между циклами: 1-3, 2-4
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    // Оставшиеся вершины (если есть) можно добавить в один из циклов или как путь
    for (int i = 6; i < n; ++i) {
        g.addEdge(i - 1, i); // соединяем в путь
    }

    return g;
}

std::string TwoBridgesGraphGenerator::name() const {
    return "2-Bridges (6 base + " + std::to_string(n - 6) + " extra)";
}