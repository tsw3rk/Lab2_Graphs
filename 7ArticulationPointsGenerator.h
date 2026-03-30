#ifndef LAB2_GRAPHS_ARTICULATIONGENERATOR_H
#define LAB2_GRAPHS_ARTICULATIONGENERATOR_H
#pragma once
#include "0IGenerator.h"

class ArticulationPointsGenerator : public IGenerator {
private:
    int n, k;
public:
    ArticulationPointsGenerator(int n, int k) : n(n), k(k) {}
    Graph generate() const override;
    std::string name() const override;
};
#endif