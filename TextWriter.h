#ifndef GRAPHLIB_TEXTWRITER_H
#define GRAPHLIB_TEXTWRITER_H

#include "Graph.h"
#include <string>
#include <vector>

class TextWriter {
public:
    static void save(const Graph& g, const std::string& filename);
    static void saveWithColors(const Graph& g, const std::string& filename,
                               const std::vector<int>& vertexColors);
};

#endif