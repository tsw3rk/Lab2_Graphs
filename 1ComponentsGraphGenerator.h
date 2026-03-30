#ifndef LAB2_GRAPHS_COMPONENTSGENERATOR_H
#define LAB2_GRAPHS_COMPONENTSGENERATOR_H
#pragma once
#include "0IGenerator.h"

class ComponentsGraphGenerator : public IGenerator {
private:
    int n;
    int k;
public:
    ComponentsGraphGenerator(int n, int k) : n(n), k(k) {}
    Graph generate() const override;
    std::string name() const override;
};
#endif