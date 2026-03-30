#ifndef LAB2_GRAPHS_WHEELGENERATOR_H
#define LAB2_GRAPHS_WHEELGENERATOR_H
#pragma once
#include "0IGenerator.h"

class WheelGraphGenerator : public IGenerator {
private:
    int n; // n >= 4: 1 центр + (n-1) на ободе
public:
    explicit WheelGraphGenerator(int n) : n(n) {}
    Graph generate() const override;
    std::string name() const override;
};
#endif