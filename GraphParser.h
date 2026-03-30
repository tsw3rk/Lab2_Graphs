#ifndef LAB2_GRAPHS_GRAPHPARSER_H
#define LAB2_GRAPHS_GRAPHPARSER_H

#pragma once

#include "Graph.h"
#include <string>

class GraphParser {
public:
    virtual ~GraphParser() = default; // Виртуальный деструктор для корректного удаления через базовый класс
    virtual Graph parse(const std::string& filename) = 0; // Чисто виртуальная функция
};

#endif //LAB2_GRAPHS_GRAPHPARSER_H