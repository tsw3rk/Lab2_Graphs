#include "DiameterCalculator.h"
#include <queue>
#include <vector>
#include <algorithm>
#include <stdexcept>

// Вспомогательная функция: запускает BFS из заданной стартовой вершины
// и возвращает максимальное расстояние до вершины.
int DiameterCalculator::bfsGetMaxDistance(const Graph& graph, int start) {
    int n = graph.getVertexCount();
    std::vector<int> dist(n, -1); // -1 означает, что вершина не посещена
    std::queue<int> q;

    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Проходим по всем соседям вершины u
        for (int v : graph.getNeighbors(u)) {
            if (dist[v] == -1) { // Если вершина v ещё не посещена
                dist[v] = dist[u] + 1; // Увеличиваем расстояние
                q.push(v);
            }
        }
    }

    // Находим максимальное расстояние среди всех вершин
    int maxDist = 0;
    for (int d : dist) {
        if (d > maxDist) {
            maxDist = d;
        }
    }
    return maxDist;
}

// Вычисляет диаметр графа: максимальное кратчайшее расстояние между двумя вершинами.
int DiameterCalculator::calculate(const Graph& graph) {
    int n = graph.getVertexCount();
    if (n == 0) return 0;
    if (n == 1) return 0;

    int diameter = 0;

    // Запускаем BFS из каждой вершины, чтобы найти макс. расстояние от неё
    for (int i = 0; i < n; ++i) {
        int maxDistFromI = bfsGetMaxDistance(graph, i);
        if (maxDistFromI > diameter) {
            diameter = maxDistFromI;
        }
    }

    return diameter;
}