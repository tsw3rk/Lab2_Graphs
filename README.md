# GraphoDro4 - Проект для работы с графами

Лабораторная работа №2 по Исследовательскому проекту.

## Структура проекта

```
GraphoDro4/
├── CMakeLists.txt          # Главный файл сборки
├── main.cpp                # Точка входа приложения
├── include/                # Заголовочные файлы (.h)
│   ├── Graph/
│   ├── Parsers/
│   ├── Serializers/
│   ├── Generators/
│   └── Algorithms/
├── src/                    # Исходные файлы (.cpp)
│   ├── Graph/
│   ├── Parsers/
│   ├── Serializers/
│   ├── Generators/
│   └── Algorithms/
├── tests/                  # Тесты
│   ├── CMakeLists.txt
│   └── test_main.cpp
└── README.md
```

## Требования к требованиям

Согласно заданию лабораторной работы:

### Для оценки 4:
- Класс графа со всей функциональностью
- 2 парсера (из 4: список ребер, матрица смежности, DIMACS, SNAP)
- 8 генераторов (из списка: Kn, Knm, Tn, Sn, Cn, Pn, Wn, G(n,p), и др.)
- 3 метрики (плотность, диаметр, транзитивность, компоненты связности, и т.д.)
- Тесты на класс граф и метрики

### Для оценки 6:
- Консольное приложение с CLI
- 3 парсера
- 12 генераторов (включая №10-13: компоненты связности, мосты, точки сочленения, 2-мосты)
- 5 метрик
- Оба сериализатора (GraphViz + Program4You)
- Тесты на генераторы

### Для оценки 8:
- Все метрики
- Все модификации сериализаторов (остов, случайный цикл, кластеры двусвязности)
- Тесты для сериализаторов

### Для оценки 10:
- ООП структура с возможностью расширения
- Сменный бекенд хранения графа

## Сборка проекта

### Linux/macOS:
```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
```

### Windows (MinGW):
```bash
mkdir build && cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
```

### Windows (Visual Studio):
```bash
mkdir build && cd build
cmake -G "Visual Studio 17 2022" ..
cmake --build . --config Release
```

## Запуск

### Приложение:
```bash
./graph_app --help
./graph_app generate complete 5
./graph_app parse graph.edges edge_list
```

### Тесты:
```bash
cd build
ctest --verbose
# или
./tests/graph_tests
```

## Опции сборки

- `-DBUILD_TESTS=OFF` - отключить сборку тестов
- `-DBUILD_APP=OFF` - отключить сборку приложения

## Зависимости

- CMake 3.15+
- C++17 компилятор (GCC 7+, Clang 5+, MSVC 2017+)
- Catch2 (загружается автоматически через FetchContent)
- Boost.Graph (опционально, если решите использовать)