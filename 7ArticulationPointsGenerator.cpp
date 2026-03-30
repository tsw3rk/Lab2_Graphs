// ArticulationPointsGenerator.cpp
#include "7ArticulationPointsGenerator.h"
#include "Graph.h"          // ← обязательно!
#include <stdexcept>
#include <string>

Graph ArticulationPointsGenerator::generate() const {
    if (n < 3 || k < 0 || k > n - 2) {
        throw std::invalid_argument("Invalid n or k (articulation points): n=" + std::to_string(n) + ", k=" + std::to_string(k));
    }

    Graph g(n);

    int current = 0;
    for (int i = 0; i < k && current + 3 <= n; ++i) {
        // Блок: цикл из 3 вершин → точка сочленения — middle = current+1
        g.addEdge(current, current + 1);
        g.addEdge(current + 1, current + 2);
        g.addEdge(current + 2, current);

        // Связь с следующим блоком через точку сочленения (current+1)
        if (i < k - 1) {
            g.addEdge(current + 1, current + 3);
        }

        current += 3;
    }

    // Оставшиеся вершины — соединяем в путь или цикл
    if (current < n) {
        for (int i = current; i < n - 1; ++i) {
            g.addEdge(i, i + 1);
        }
        // Если осталось ≥3 вершин — замкнём в цикл (чтобы не создавать новые точки сочленения)
        if (n - current >= 3) {
            g.addEdge(current, n - 1);
        }
    }

    return g;
}

std::string ArticulationPointsGenerator::name() const {
    return "Articulation (" + std::to_string(n) + "v, " + std::to_string(k) + " ap)";
}