#ifndef LAB2_GRAPHS_CUBICGENERATOR_H
#define LAB2_GRAPHS_CUBICGENERATOR_H
#pragma once
#include "0IGenerator.h"

class CubicGraphGenerator : public IGenerator {
private:
    int n; // n must be even and >= 4
public:
    explicit CubicGraphGenerator(int n) : n(n) {}
    Graph generate() const override;
    std::string name() const override;
};
#endif