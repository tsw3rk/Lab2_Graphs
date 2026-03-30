#ifndef LAB2_GRAPHS_BIPARTITEGENERATOR_H
#define LAB2_GRAPHS_BIPARTITEGENERATOR_H
#pragma once
#include "0IGenerator.h"

class BipartiteGraphGenerator : public IGenerator {
private:
    int n, m;
public:
    BipartiteGraphGenerator(int n, int m) : n(n), m(m) {}
    Graph generate() const override;
    std::string name() const override;
};
#endif