#ifndef LAB2_GRAPHS_ADJACENCYMATRIXPARSER_H

#define LAB2_GRAPHS_ADJACENCYMATRIXPARSER_H
#pragma once

#include "GraphParser.h"

class AdjacencyMatrixParser : public GraphParser {
public:
    Graph parse(const std::string& filename) override;

};
#endif //LAB2_GRAPHS_ADJACENCYMATRIXPARSER_H