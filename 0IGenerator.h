#ifndef LAB2_GRAPHS_IGENERATOR_H
#define LAB2_GRAPHS_IGENERATOR_H
#pragma once
#include "Graph.h"

class IGenerator {
public:
    virtual ~IGenerator() = default;
    virtual Graph generate() const = 0;
    virtual std::string name() const = 0;
};
#endif