#ifndef LAB2_GRAPHS_ARTICULATIONPOINTSCALCULATOR_H
#define LAB2_GRAPHS_ARTICULATIONPOINTSCALCULATOR_H

#pragma once
#include "../Graph.h"
#include <vector>

class ArticulationPointsCalculator {
public:
    static int calculate(const Graph& graph);
private:
    static void dfs(int u, std::vector<std::vector<int>>& adj, std::vector<int>& disc, std::vector<int>& low, std::vector<int>& parent, std::vector<bool>& articulationPoint, int& time);
};

#endif //LAB2_GRAPHS_ARTICULATIONPOINTSCALCULATOR_H