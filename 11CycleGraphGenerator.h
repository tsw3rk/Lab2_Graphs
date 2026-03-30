#ifndef LAB2_GRAPHS_CYCLEGENERATOR_H
#define LAB2_GRAPHS_CYCLEGENERATOR_H
#pragma once
#include "0IGenerator.h"

class CycleGraphGenerator : public IGenerator {
private:
    int n;
public:
    explicit CycleGraphGenerator(int n) : n(n) {}
    Graph generate() const override;
    std::string name() const override;
};
#endif