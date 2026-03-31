#include "TransitivityCalculator.h"
#include <set>
#include <vector>
#include <algorithm>

// Вспомогательная функция: подсчитывает количество треугольников в графе.
int TransitivityCalculator::countTriangles(const Graph& graph) {
    int n = graph.getVertexCount();
    int triangles = 0;

    // Перебираем все возможные тройки вершин (i, j, k)
    for (int i = 0; i < n; ++i) {
        std::vector<int> neighbors = graph.getNeighbors(i);

        for (size_t j_idx = 0; j_idx < neighbors.size(); ++j_idx) {
            int j = neighbors[j_idx];
            if (j <= i) continue; // Чтобы не пересекаться с другими рёбрами

            for (size_t k_idx = j_idx + 1; k_idx < neighbors.size(); ++k_idx) {
                int k = neighbors[k_idx];
                if (k <= j) continue;

                // Проверяем, есть ли ребро между j и k
                if (graph.hasEdge(j, k)) {
                    triangles++;
                }
            }
        }
    }

    return triangles;
}

// Вспомогательная функция: подсчитывает количество триад (соединённых троек вершин).
int TransitivityCalculator::countTriads(const Graph& graph) {
    int n = graph.getVertexCount();
    int triads = 0;

    for (int i = 0; i < n; ++i) {
        std::vector<int> neighbors = graph.getNeighbors(i);
        int degree = neighbors.size();

        // Число возможных пар соседей вершины i: C(degree, 2) = degree * (degree - 1) / 2
        triads += degree * (degree - 1) / 2;
    }

    return triads;
}

// Вычисляет транзитивность: отношение числа треугольников к числу триад.
double TransitivityCalculator::calculate(const Graph& graph) {
    int triads = countTriads(graph);
    if (triads == 0) {
        return 0.0; // Если нет триад, транзитивность 0
    }

    int triangles = countTriangles(graph);
    return (3.0 * triangles) / triads; // 3.0 — потому что каждый треугольник считается 3 раза
}