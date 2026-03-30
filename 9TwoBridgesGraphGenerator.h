#ifndef LAB2_GRAPHS_TWOBRIDGESGENERATOR_H
#define LAB2_GRAPHS_TWOBRIDGESGENERATOR_H
#pragma once
#include "0IGenerator.h"

class TwoBridgesGraphGenerator : public IGenerator {
private:
    int n; // n >= 6: 2 цикла по 3 вершины + 2 моста между ними
public:
    explicit TwoBridgesGraphGenerator(int n) : n(n) {}
    Graph generate() const override;
    std::string name() const override;
};
#endif