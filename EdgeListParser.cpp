#include "EdgeListParser.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

Graph EdgeListParser::parse(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + filename);
    }

    int n, m;
    file >> n >> m;

    if (n <= 0) {
        throw std::runtime_error("Number of vertices must be positive.");
    }

    Graph graph(n); // Создаём граф с n вершинами

    int u, v;
    for (int i = 0; i < m; ++i) {
        file >> u >> v;

        // Проверяем диапазон (вершины от 0 до n-1)
        if (u < 0 || u >= n || v < 0 || v >= n) {
            throw std::runtime_error("Invalid vertex index in edge: " + std::to_string(u) + " " + std::to_string(v));
        }

        graph.addEdge(u, v);
    }

    // Проверяем, что мы действительно прочитали M рёбер
    if (file.eof() && i < m) {
        throw std::runtime_error("File ended before reading all expected edges.");
    }

    return graph;
}