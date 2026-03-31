#include "DensityCalculator.h"
#include <cmath> // если понадобится

double DensityCalculator::calculate(const Graph& graph) {
    int n = graph.getVertexCount();
    if (n <= 1) return 0.0;

    int possibleEdges = n * (n - 1) / 2; // для неориентированного графа
    int actualEdges = 0;

    for (int i = 0; i < n; ++i) {
        actualEdges += graph.getNeighbors(i).size();
    }
    actualEdges /= 2; // потому что каждое ребро посчитано дважды

    return static_cast<double>(actualEdges) / possibleEdges;
}