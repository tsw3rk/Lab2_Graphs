#include "1ComponentsGraphGenerator.h"
#include <stdexcept>

Graph ComponentsGraphGenerator::generate() const {
    if (n < 1 || k < 1 || k > n) {
        throw std::invalid_argument("Invalid n or k (components)");
    }
    Graph g(n);

    int base = n / k;
    int rem = n % k;
    int start = 0;

    for (int c = 0; c < k; ++c) {
        int size = base + (c < rem ? 1 : 0);
        if (size == 1) {
            // изолированная вершина — ничего не делаем
        } else if (size == 2) {
            g.addEdge(start, start + 1);
        } else {
            // цикл внутри компоненты
            for (int i = 0; i < size; ++i) {
                g.addEdge(start + i, start + (i + 1) % size);
            }
        }
        start += size;
    }
    return g;
}

std::string ComponentsGraphGenerator::name() const {
    return "Components (" + std::to_string(n) + "v, " + std::to_string(k) + " comp)";
}