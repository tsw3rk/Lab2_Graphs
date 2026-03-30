cmake_minimum_required(VERSION 3.15)
project(GraphoDro4 VERSION 1.0 LANGUAGES CXX)

# Стандарт C++17 или выше (нужен для std::filesystem, structured bindings и т.д.)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Для IDE

# Опции для включения/выключения компонентов
option(BUILD_TESTS "Build unit tests" ON)
option(BUILD_APP "Build console application" ON)

# --- Библиотека графов (Core Library) ---
# Собираем все исходники в статическую библиотеку для удобства линковки тестов и аппа
# Пока нет файлов, создаем пустую библиотеку

set(LIB_SOURCES "")

file(GLOB_RECURSE GRAPH_SOURCES "${CMAKE_SOURCE_DIR}/src/Graph/*.cpp")
if(GRAPH_SOURCES)
    list(APPEND LIB_SOURCES ${GRAPH_SOURCES})
endif()

file(GLOB_RECURSE PARSER_SOURCES "${CMAKE_SOURCE_DIR}/src/Parsers/*.cpp")
if(PARSER_SOURCES)
    list(APPEND LIB_SOURCES ${PARSER_SOURCES})
endif()

file(GLOB_RECURSE SERIALIZER_SOURCES "${CMAKE_SOURCE_DIR}/src/Serializers/*.cpp")
if(SERIALIZER_SOURCES)
    list(APPEND LIB_SOURCES ${SERIALIZER_SOURCES})
endif()

file(GLOB_RECURSE GENERATOR_SOURCES "${CMAKE_SOURCE_DIR}/src/Generators/*.cpp")
if(GENERATOR_SOURCES)
    list(APPEND LIB_SOURCES ${GENERATOR_SOURCES})
endif()

file(GLOB_RECURSE ALGORITHM_SOURCES "${CMAKE_SOURCE_DIR}/src/Algorithms/*.cpp")
if(ALGORITHM_SOURCES)
    list(APPEND LIB_SOURCES ${ALGORITHM_SOURCES})
endif()

# Если файлов нет, создаем заглушку чтобы библиотека компилировалась
if(NOT LIB_SOURCES)
    set(LIB_SOURCES "${CMAKE_SOURCE_DIR}/src/dummy.cpp")
endif()

add_library(graph_lib STATIC ${LIB_SOURCES})
target_include_directories(graph_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Если потребуется Boost (опционально, пока закомментировано)
# find_package(Boost REQUIRED COMPONENTS graph)
# target_link_libraries(graph_lib PUBLIC Boost::graph)

# --- Консольное приложение (Console App) ---
if(BUILD_APP)
    add_executable(graph_app main.cpp)
    target_link_libraries(graph_app PRIVATE graph_lib)
    
    # Если есть отдельный код приложения в src/App
    file(GLOB APP_SOURCES "${CMAKE_SOURCE_DIR}/src/App/*.cpp")
    if(APP_SOURCES)
        target_sources(graph_app PRIVATE ${APP_SOURCES})
    endif()
endif()

# --- Тесты (Tests) ---
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# --- Вывод информации ---
message(STATUS "Building GraphoDro4...")
message(STATUS "  Build Tests: ${BUILD_TESTS}")
message(STATUS "  Build App: ${BUILD_APP}")
