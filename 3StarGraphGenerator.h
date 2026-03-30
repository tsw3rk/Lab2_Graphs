#ifndef LAB2_GRAPHS_STARGENERATOR_H
#define LAB2_GRAPHS_STARGENERATOR_H
#pragma once
#include "0IGenerator.h"

class StarGraphGenerator : public IGenerator {
private:
    int n;
public:
    explicit StarGraphGenerator(int n) : n(n) {}
    Graph generate() const override;
    std::string name() const override;
};
#endif