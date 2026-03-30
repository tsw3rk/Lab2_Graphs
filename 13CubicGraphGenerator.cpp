#include "13CubicGraphGenerator.h"
#include <stdexcept>

Graph CubicGraphGenerator::generate() const {
    if (n < 4 || n % 2 != 0) {
        throw std::invalid_argument("Cubic graph requires even n >= 4");
    }
    Graph g(n);

    // Простая стратегия: цикл + "хорды"
    // Каждая вершина соединена с 3 другими: i-1, i+1, i+n/2
    for (int i = 0; i < n; ++i) {
        g.addEdge(i, (i + 1) % n); // цикл
        g.addEdge(i, (i + n / 2) % n); // хорда
        // Третье ребро: i <-> (i-1+n)%n (уже есть от соседа i-1)
        // На самом деле, это будет 3-регулярный граф
    }

    return g;
}
std::string CubicGraphGenerator::name() const {
    return "Cubic (" + std::to_string(n) + "v)";
}