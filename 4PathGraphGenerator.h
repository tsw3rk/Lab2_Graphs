#ifndef LAB2_GRAPHS_PATHGENERATOR_H
#define LAB2_GRAPHS_PATHGENERATOR_H
#pragma once
#include "0IGenerator.h"

class PathGraphGenerator : public IGenerator {
private:
    int n;
public:
    explicit PathGraphGenerator(int n) : n(n) {}
    Graph generate() const override;
    std::string name() const override;
};
#endif