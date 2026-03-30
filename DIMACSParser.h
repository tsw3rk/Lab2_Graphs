#ifndef LAB2_GRAPHS_DIMACSPARSER_H
#define LAB2_GRAPHS_DIMACSPARSER_H
#pragma once

#include "GraphParser.h"

class DIMACSParser : public GraphParser {
public:
    Graph parse(const std::string& filename) override;
};

#endif // LAB2_GRAPHS_DIMACSPARSER_H
