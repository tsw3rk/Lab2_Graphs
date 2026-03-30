cmake_minimum_required(VERSION 3.10)

project(GraphoDro4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCES
        main.cpp
        Graph.cpp
        AdjacencyMatrixParser.cpp
        EdgeListParser.cpp
        DIMACSParser.cpp  # ← Добавил N (1)
)

set(HEADERS
        Graph.h
        GraphParser.h
        AdjacencyMatrixParser.h
        EdgeListParser.h
        DIMACSParser.h    Добавил N (1)
)

add_executable(graph_app ${SOURCES} ${HEADERS})