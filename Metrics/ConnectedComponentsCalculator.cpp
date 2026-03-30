#include "ConnectedComponentsCalculator.h"
#include <vector>

// Вспомогательная функция: запускает DFS из вершины u, помечая все достижимые вершины.
void ConnectedComponentsCalculator::dfs(const Graph& graph, int u, std::vector<bool>& visited) {
    visited[u] = true;

    // Проходим по всем соседям вершины u
    for (int v : graph.getNeighbors(u)) {
        if (!visited[v]) {
            dfs(graph, v, visited);
        }
    }
}

// Подсчитывает количество компонент связности в графе.
int ConnectedComponentsCalculator::calculate(const Graph& graph) {
    int n = graph.getVertexCount();
    if (n == 0) return 0;

    std::vector<bool> visited(n, false); // Массив для отслеживания посещённых вершин
    int components = 0;

    // Проходим по всем вершинам
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            // Если вершина не посещена, запускаем DFS и увеличиваем счётчик компонент
            dfs(graph, i, visited);
            components++;
        }
    }

    return components;
}