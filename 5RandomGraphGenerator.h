#ifndef LAB2_GRAPHS_RANDOMGENERATOR_H
#define LAB2_GRAPHS_RANDOMGENERATOR_H
#pragma once
#include "0IGenerator.h"
#include <random>

class RandomGraphGenerator : public IGenerator {
private:
    int n;
    double p;
    unsigned int seed;
public:
    RandomGraphGenerator(int n, double p, unsigned int seed = 42)
        : n(n), p(p), seed(seed) {}
    Graph generate() const override;
    std::string name() const override;
};
#endif