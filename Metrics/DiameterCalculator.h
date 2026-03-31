#ifndef LAB2_GRAPHS_DIAMETERCALCULATOR_H
#define LAB2_GRAPHS_DIAMETERCALCULATOR_H

#pragma once
#include "../Graph.h"
#include <vector>

class DiameterCalculator {
public:
    static int calculate(const Graph& graph);
private:
    static int bfsGetMaxDistance(const Graph& graph, int start);
};

#endif //LAB2_GRAPHS_DIAMETERCALCULATOR_H