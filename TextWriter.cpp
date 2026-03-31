#include "TextWriter.h"
#include <fstream>
#include <stdexcept>

//для Progr@m4You .edges

void TextWriter::save(const Graph& g, const std::string& filename) {
    std::ofstream out(filename);
    if (!out.is_open()) {
        throw std::runtime_error("Cannot open file for writing: " + filename);
    }

    int n = g.getVertexCount();
    int m = g.getEdgeCount();

    out << n << " " << m << "\n";

    for (int i = 0; i < n; ++i) {
        for (int j : g.getNeighbors(i)) {
            if (i < j) {
                out << i << " " << j << "\n";
            }
        }
    }

    out.close();
}

void TextWriter::saveWithColors(const Graph& g, const std::string& filename,
                                const std::vector<int>& vertexColors) {
    std::ofstream out(filename);
    if (!out.is_open()) {
        throw std::runtime_error("Cannot open file for writing: " + filename);
    }

    int n = g.getVertexCount();
    int m = g.getEdgeCount();

    out << n << " " << m << "\n";

    out << "# Colors\n";
    for (int i = 0; i < n; ++i) {
        if (i < static_cast<int>(vertexColors.size())) {
            out << i << " " << vertexColors[i] << "\n";
        } else {
            out << i << " 0\n";
        }
    }

    out << "# Edges\n";
    for (int i = 0; i < n; ++i) {
        for (int j : g.getNeighbors(i)) {
            if (i < j) {
                out << i << " " << j << "\n";
            }
        }
    }

    out.close();
}