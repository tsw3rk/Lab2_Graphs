// main.cpp - точка входа консольного приложения
// Для оценки 6+ нужно реализовать парсинг аргументов командной строки

#include <iostream>
#include <string>
#include <filesystem>

// Заголовочные файлы вашего проекта (пример)
// #include "Graph/Graph.h"
// #include "Parsers/ParserFactory.h"
// #include "Generators/GeneratorFactory.h"
// #include "Algorithms/MetricsCalculator.h"
// #include "Serializers/SerializerFactory.h"

void printHelp() {
    std::cout << "GraphoDro4 - инструмент для работы с графами\n";
    std::cout << "Использование:\n";
    std::cout << "  graph_app [command] [options]\n\n";
    std::cout << "Команды:\n";
    std::cout << "  generate <type> <args>  - сгенерировать граф\n";
    std::cout << "  parse <file> <format>   - загрузить граф из файла\n";
    std::cout << "  metrics <graph>         - вычислить метрики графа\n";
    std::cout << "  visualize <graph>       - сериализовать в GraphViz/Program4You\n";
    std::cout << "  test                    - запустить тесты\n\n";
    std::cout << "Примеры:\n";
    std::cout << "  graph_app generate complete 5\n";
    std::cout << "  graph_app parse graph.edges edge_list\n";
    std::cout << "  graph_app metrics my_graph\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printHelp();
        return 0;
    }

    std::string command = argv[1];

    if (command == "--help" || command == "-h") {
        printHelp();
        return 0;
    }

    // TODO: Реализовать обработку команд
    // В зависимости от команды:
    // 1. Создать нужный генератор/парсер/алгоритм через фабрику
    // 2. Выполнить операцию
    // 3. Вывести результат или сохранить в файл

    std::cout << "Команда '" << command << "' пока не реализована.\n";
    std::cout << "Реализуйте логику обработки команд в main.cpp\n";

    return 0;
}