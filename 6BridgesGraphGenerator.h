#ifndef LAB2_GRAPHS_BRIDGESGENERATOR_H
#define LAB2_GRAPHS_BRIDGESGENERATOR_H
#pragma once
#include "0IGenerator.h"

class BridgesGraphGenerator : public IGenerator {
private:
    int n, k; // n вершин, k мостов
public:
    BridgesGraphGenerator(int n, int k) : n(n), k(k) {}
    Graph generate() const override;
    std::string name() const override;
};
#endif