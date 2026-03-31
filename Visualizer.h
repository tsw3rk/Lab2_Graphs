#ifndef GRAPHLIB_VISUALIZER_H
#define GRAPHLIB_VISUALIZER_H

#include "Graph.h"
#include <string>
#include <vector>
#include <utility>

class Visualizer {
public:
    static void save(const Graph& g, const std::string& filename,
                     const std::vector<int>& vertexColors = {},
                     const std::vector<std::pair<int, int>>& highlightedEdges = {});
    static void saveWithSpanningTree(const Graph& g, const std::string& filename, unsigned int seed = 42);
    static void saveWithRandomCycle(const Graph& g, const std::string& filename, unsigned int seed = 42);

private:
    static std::vector<std::pair<int, int>> findSpanningTree(const Graph& g, unsigned int seed);
    static std::vector<int> findRandomCycle(const Graph& g, unsigned int seed);
};

#endif