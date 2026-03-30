 #ifndef LAB2_GRAPHS_GRAPH_H
#define LAB2_GRAPHS_GRAPH_H

#pragma once

#include <vector>
#include <set>

class Graph {
private:
    int vertexCount;           // Количество вершин
    std::vector<std::set<int>> adjacencyList; // Список смежности

public:
    explicit Graph(int n); // Конструктор: создаёт граф с n вершинами и без рёбер

    // Методы для работы с графом
    int getVertexCount() const;
    void addEdge(int u, int v); // Добавить ребро (неориентированное)
    bool hasEdge(int u, int v) const; // Проверить наличие ребра
    std::vector<int> getNeighbors(int u) const; // Получить список соседей вершины u
};
#endif //LAB2_GRAPHS_GRAPH_H