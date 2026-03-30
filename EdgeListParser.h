#ifndef LAB2_GRAPHS_EDGELISTPARSER_H
#define LAB2_GRAPHS_EDGELISTPARSER_H

#pragma once

#include "GraphParser.h"

class EdgeListParser : public GraphParser {
public:
    Graph parse(const std::string& filename) override;
};

#endif //LAB2_GRAPHS_EDGELISTPARSER_H