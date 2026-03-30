cmake_minimum_required(VERSION 3.10)

project(GraphoDro4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCES
        SOURCES
        main.cpp
        Graph.cpp
        AdjacencyMatrixParser.cpp
        EdgeListParser.cpp
        DIMACSParser.cpp
        BipartiteGraphGenerator.cpp
        StarGraphGenerator.cpp
        PathGraphGenerator.cpp
        RandomGraphGenerator.cpp
        ComponentsGraphGenerator.cpp
        ArticulationPointsGenerator.cpp
        HalinGraphGenerator.cpp
        CompleteGraphGenerator.cpp
        TreeGraphGenerator.cpp
        CycleGraphGenerator.cpp
        WheelGraphGenerator.cpp
        CubicGraphGenerator.cpp
        BridgesGraphGenerator.cpp
        TwoBridgesGraphGenerator.cpp
)

set(HEADERS
        HEADERS
        Graph.h
        GraphParser.h
        AdjacencyMatrixParser.h
        EdgeListParser.h
        DIMACSParser.h
        IGenerator.h
        BipartiteGraphGenerator.h
        StarGraphGenerator.h
        PathGraphGenerator.h
        RandomGraphGenerator.h
        ComponentsGraphGenerator.h
        ArticulationPointsGenerator.h
        HalinGraphGenerator.h
        CompleteGraphGenerator.h
        TreeGraphGenerator.h
        CycleGraphGenerator.h
        WheelGraphGenerator.h
        CubicGraphGenerator.h
        BridgesGraphGenerator.h
        TwoBridgesGraphGenerator.h
)

add_executable(graph_app ${SOURCES} ${HEADERS})