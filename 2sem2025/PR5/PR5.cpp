#include <iostream>
#include "ClassGraph.h"
#include "Windows.h"

using namespace std;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //if (argc < 2) {
    //    cerr << "Usage: " << argv[0] << " <input_file>" << endl;
    //    return 1;
    //}

    try {
        ClassGraph graph;  //27 var
        //graph.loadFromAdjacencyMatrix(argv[1]);
        graph.loadFromAdjacencyMatrix("data.txt");
        cout << "Информация о графе:" << endl;
        cout << graph;
        int startVertex = 0; // Начальная вершина
        string outputFile = "data_shortest_paths.txt";
        graph.findShortestPaths(startVertex, outputFile);
    }
    catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}
