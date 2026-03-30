#ifndef LAB2_GRAPHS_TREEGENERATOR_H
#define LAB2_GRAPHS_TREEGENERATOR_H
#pragma once
#include "0IGenerator.h"
#include <random>

class TreeGraphGenerator : public IGenerator {
private:
    int n;
    unsigned int seed;
public:
    TreeGraphGenerator(int n, unsigned int seed = 42) : n(n), seed(seed) {}
    Graph generate() const override;
    std::string name() const override;
};
#endif