#ifndef LAB2_GRAPHS_HALINGENERATOR_H
#define LAB2_GRAPHS_HALINGENERATOR_H
#pragma once
#include "0IGenerator.h"

class HalinGraphGenerator : public IGenerator {
private:
    int m; // количество листьев (тогда n = m + 1)
public:
    explicit HalinGraphGenerator(int m) : m(m) {}
    Graph generate() const override;
    std::string name() const override;
};
#endif