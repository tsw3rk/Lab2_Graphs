#include "6BridgesGraphGenerator.h"
#include <stdexcept>

Graph BridgesGraphGenerator::generate() const {
    if (n < 2 || k < 0 || k > n - 1) {
        throw std::invalid_argument("Invalid n or k (bridges)");
    }
    Graph g(n);

    // Создаём цепочку из k мостов: 0-1-2-...-k
    for (int i = 0; i < k && i < n - 1; ++i) {
        g.addEdge(i, i + 1);
    }

    // Оставшиеся вершины (n - k - 1) соединяем в цикл (если >= 3)
    int remaining = n - k - 1;
    if (remaining >= 2) {
        int start = k + 1; // первая вершина после цепочки
        for (int i = 0; i < remaining; ++i) {
            g.addEdge(start + i, start + (i + 1) % remaining);
        }
        // Соединим цикл с цепочкой, чтобы не создавать лишнюю компоненту
        if (k >= 0) {
            g.addEdge(k, start); // соединяем конец цепочки с началом цикла
        }
    } else if (remaining == 1 && k >= 0) {
        // Одна вершина — соединяем с концом цепочки
        g.addEdge(k, k + 1);
    }

    return g;
}

std::string BridgesGraphGenerator::name() const {
    return "Bridges (" + std::to_string(n) + "v, " + std::to_string(k) + " bridges)";
}