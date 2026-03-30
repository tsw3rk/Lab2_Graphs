#ifndef LAB2_GRAPHS_TRANSITIVITYCALCULATOR_H
#define LAB2_GRAPHS_TRANSITIVITYCALCULATOR_H

#pragma once
#include "../Graph.h"
#include <vector>

class TransitivityCalculator {
public:
    static double calculate(const Graph& graph);
private:
    static int countTriangles(const Graph& graph);
    static int countTriads(const Graph& graph);
};

#endif //LAB2_GRAPHS_TRANSITIVITYCALCULATOR_H