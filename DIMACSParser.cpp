#include "DIMACSParser.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cctype>

Graph DIMACSParser::parse(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open DIMACS file: " + filename);
    }

    int n = 0, m = 0;
    std::string line;

    // Пропускаем комментарии и ищем строку заголовка: p edge n m
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == 'c') {
            continue;
        }
        if (line[0] == 'p') {
            std::istringstream iss(line);
            std::string p, edge;
            iss >> p >> edge >> n >> m;
            if (edge != "edge") {
                throw std::runtime_error("Expected 'p edge' in DIMACS header, got: " + edge);
            }
            break;
        }
    }

    if (n <= 0) {
        throw std::runtime_error("Invalid or missing vertex count in DIMACS file");
    }

    Graph graph(n);

    // Сбрасываем позицию и читаем рёбра
    file.clear();
    file.seekg(0);

    while (std::getline(file, line)) {
        if (line.empty() || line[0] == 'c' || line[0] == 'p') {
            continue;
        }
        if (line[0] == 'e') {
            std::istringstream iss(line);
            std::string e;
            int u, v;
            iss >> e >> u >> v;

            // Проверка корректности индексов (DIMACS использует 1-индексацию)
            if (u < 1 || v < 1 || u > n || v > n) {
                throw std::runtime_error(
                    "Vertex index out of bounds in DIMACS: " + std::to_string(u) + ", " + std::to_string(v) +
                    " (expected 1.." + std::to_string(n) + ")"
                );
            }

            // Переводим в 0-индексацию и добавляем ребро
            graph.addEdge(u - 1, v - 1);
        }
    }

    return graph;
}