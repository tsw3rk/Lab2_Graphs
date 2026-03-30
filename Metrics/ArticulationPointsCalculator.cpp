// Metrics/ArticulationPointsCalculator.cpp
#include "ArticulationPointsCalculator.h"
#include <vector>
#include <algorithm>

// Основная функция DFS точек сочленения.
void ArticulationPointsCalculator::dfs(
    int u,
    std::vector<std::vector<int>>& adj,
    std::vector<int>& disc,
    std::vector<int>& low,
    std::vector<int>& parent,
    std::vector<bool>& articulationPoint,
    int& time
) {
    int children = 0; // Счётчик детей текущей вершины в DFS дереве

    disc[u] = low[u] = time++; // Время обнаружения и "нижнее" время
    for (int v : adj[u]) {
        if (disc[v] == -1) { // Если v ещё не посещена (часть DFS дерева)
            parent[v] = u;
            children++;
            dfs(v, adj, disc, low, parent, articulationPoint, time);

            // Обновляем low[u] на основе low[v]
            low[u] = std::min(low[u], low[v]);

            // Если u — корень и имеет больше одного ребёнка, то это точка сочленения
            if (parent[u] == -1 && children > 1) {
                articulationPoint[u] = true;
            }

            // Если u — не корень и low[v] >= disc[u], то u — точка сочленения
            if (parent[u] != -1 && low[v] >= disc[u]) {
                articulationPoint[u] = true;
            }
        }
        else if (v != parent[u]) { // Обратное ребро (не возвращаемся к родителю)
            low[u] = std::min(low[u], disc[v]);
        }
    }
}

// Подсчитывает количество точек сочленения в графе.
int ArticulationPointsCalculator::calculate(const Graph& graph) {
    int n = graph.getVertexCount();
    if (n == 0) return 0;

    // Преобразуем Graph в список смежности для удобства работы с DFS
    std::vector<std::vector<int>> adj(n);
    for (int u = 0; u < n; ++u) {
        adj[u] = graph.getNeighbors(u);
    }

    std::vector<int> disc(n, -1);      // Время открытия
    std::vector<int> low(n, -1);       // Минимальное время открытия в поддереве
    std::vector<int> parent(n, -1);    // Родитель в DFS дереве
    std::vector<bool> articulationPoint(n, false); // Является ли вершина точкой сочленения
    int time = 0;

    // Запускаем DFS для каждой не посещённой вершины
    for (int i = 0; i < n; ++i) {
        if (disc[i] == -1) {
            dfs(i, adj, disc, low, parent, articulationPoint, time);
        }
    }

    // Подсчитываем количество точек сочленения
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (articulationPoint[i]) {
            count++;
        }
    }

    return count;
}