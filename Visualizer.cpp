#include "Visualizer.h"
#include <fstream>
#include <random>
#include <algorithm>
#include <unordered_set>
#include <functional>
#include <stdexcept>

//для GraphViz

std::vector<std::pair<int, int>> Visualizer::findSpanningTree(const Graph& g, unsigned int seed) {
    std::vector<std::pair<int, int>> treeEdges;
    int n = g.getVertexCount();
    if (n == 0) return treeEdges;

    std::vector<bool> visited(n, false);
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dis(0, n - 1);

    int start = dis(gen);

    std::function<void(int)> dfs = [&](int v) {
        visited[v] = true;
        auto neighbors = g.getNeighbors(v);
        std::shuffle(neighbors.begin(), neighbors.end(), gen);

        for (int u : neighbors) {
            if (!visited[u]) {
                treeEdges.emplace_back(v, u);
                dfs(u);
            }
        }
    };

    dfs(start);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    return treeEdges;
}

std::vector<int> Visualizer::findRandomCycle(const Graph& g, unsigned int seed) {
    int n = g.getVertexCount();
    if (n < 3) return {};

    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dis(0, n - 1);

    for (int attempt = 0; attempt < 10; ++attempt) {
        int start = dis(gen);
        std::vector<bool> visited(n, false);
        std::vector<int> path;
        std::vector<int> parent(n, -1);
        std::vector<int> foundCycle;

        std::function<bool(int)> dfs = [&](int v) -> bool {
            visited[v] = true;
            path.push_back(v);

            auto neighbors = g.getNeighbors(v);
            std::shuffle(neighbors.begin(), neighbors.end(), gen);

            for (int u : neighbors) {
                if (u == parent[v]) continue;

                if (visited[u]) {
                    auto it = std::find(path.begin(), path.end(), u);
                    if (it != path.end()) {
                        foundCycle.assign(it, path.end());
                        return true;
                    }
                } else {
                    parent[u] = v;
                    if (dfs(u)) {
                        return true;
                    }
                }
            }
            path.pop_back();
            return false;
        };

        if (dfs(start) && !foundCycle.empty()) {
            if (foundCycle.size() >= 3) {
                return foundCycle;
            }
        }
    }

    return {};
}

void Visualizer::save(const Graph& g, const std::string& filename,
                      const std::vector<int>& vertexColors,
                      const std::vector<std::pair<int, int>>& highlightedEdges) {
    std::ofstream out(filename);
    if (!out.is_open()) {
        throw std::runtime_error("Cannot open file for writing: " + filename);
    }

    int n = g.getVertexCount();

    out << "graph G {\n";
    out << "  layout=neato;\n";
    out << "  overlap=false;\n";

    std::unordered_set<std::string> highlightSet;
    for (const auto& e : highlightedEdges) {
        int u = std::min(e.first, e.second);
        int v = std::max(e.first, e.second);
        highlightSet.insert(std::to_string(u) + "-" + std::to_string(v));
    }

    for (int i = 0; i < n; ++i) {
        out << "  " << i;
        if (!vertexColors.empty() && i < static_cast<int>(vertexColors.size())) {
            int col = vertexColors[i] % 10;
            std::string color_str = (col == 0) ? "lightblue" :
                                   (col == 1) ? "lightgreen" :
                                   (col == 2) ? "pink" :
                                   (col == 3) ? "yellow" :
                                   (col == 4) ? "orange" :
                                   (col == 5) ? "red" :
                                   (col == 6) ? "purple" :
                                   (col == 7) ? "cyan" :
                                   (col == 8) ? "magenta" : "gray";
            out << " [fillcolor=" << color_str << ", style=filled]";
        }
        out << ";\n";
    }

    for (int i = 0; i < n; ++i) {
        for (int j : g.getNeighbors(i)) {
            if (i < j) {
                out << "  " << i << " -- " << j;
                std::string edge_key = std::to_string(std::min(i, j)) + "-" + std::to_string(std::max(i, j));
                if (highlightSet.count(edge_key)) {
                    out << " [color=red, penwidth=3.0]";
                }
                out << ";\n";
            }
        }
    }

    out << "}\n";
    out.close();
}

void Visualizer::saveWithSpanningTree(const Graph& g, const std::string& filename, unsigned int seed) {
    auto treeEdges = findSpanningTree(g, seed);
    save(g, filename, {}, treeEdges);
}

void Visualizer::saveWithRandomCycle(const Graph& g, const std::string& filename, unsigned int seed) {
    auto cycle = findRandomCycle(g, seed);
    std::vector<std::pair<int, int>> cycleEdges;
    if (cycle.size() >= 3) {
        for (size_t i = 0; i < cycle.size(); ++i) {
            int u = cycle[i];
            int v = cycle[(i + 1) % cycle.size()];
            cycleEdges.emplace_back(u, v);
        }
    }
    save(g, filename, {}, cycleEdges);
}