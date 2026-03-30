#ifndef LAB2_GRAPHS_CONNECTEDCOMPONENTSCALCULATOR_H
#define LAB2_GRAPHS_CONNECTEDCOMPONENTSCALCULATOR_H

#pragma once
#include "../Graph.h"
#include <vector>

class ConnectedComponentsCalculator {
public:
    static int calculate(const Graph& graph);
private:
    static void dfs(const Graph& graph, int u, std::vector<bool>& visited);
};

#endif //LAB2_GRAPHS_CONNECTEDCOMPONENTSCALCULATOR_H