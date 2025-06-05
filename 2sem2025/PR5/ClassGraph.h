#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <climits>
#include <stdexcept>

using namespace std;

class ClassGraph {
private:
    vector<vector<int>> adjacencyMatrix;
public:
    ClassGraph() : vertexCount(0) {}
    ~ClassGraph() = default;
    int vertexCount;

    void loadFromAdjacencyMatrix(const string& filename) {
        ifstream file(filename);
        if (!file) {
            throw runtime_error("Файл не найдет: " + filename);
        }
        file >> vertexCount;
        adjacencyMatrix.resize(vertexCount, vector<int>(vertexCount));
        for (int i = 0; i < vertexCount; ++i) {
            for (int j = 0; j < vertexCount; ++j) {
                file >> adjacencyMatrix[i][j];
            }
        }
    };

    void DFS(int vertex, vector<bool>& visited, vector<int>& traversalOrder)
    {
        visited[vertex] = true;
        traversalOrder.push_back(vertex);
        for (int i = 0; i < vertexCount; ++i) {
            if (adjacencyMatrix[vertex][i] != 0 && !visited[i]) {
                DFS(i, visited, traversalOrder);
            }
        }
    };


    void printGraph(ostream& os)
    {
        vector<bool> visited(vertexCount, false);
        vector<int> traversalOrder;
        for (int i = 0; i < vertexCount; ++i) {
            if (!visited[i]) {
                const_cast<ClassGraph*>(this)->DFS(i, visited, traversalOrder);
            }
        }
        os << "Обход графа алгоритмом поиск в глубину (DFS): ";
        for (int v : traversalOrder) {
            os << v << " ";
        }
        os << "\n";
    };
    void findShortestPaths(int startVertex, const string& outputFilename)
    {
        vector<int> distances(vertexCount, INT_MAX);
        vector<bool> visited(vertexCount, false);
        distances[startVertex] = 0;
        for (int count = 0; count < vertexCount - 1; ++count) {
            int min = INT_MAX, minIndex = -1;

            for (int v = 0; v < vertexCount; ++v) {
                if (!visited[v] && distances[v] <= min) {
                    min = distances[v];
                    minIndex = v;
                }
            }
            if (minIndex == -1) break;
            visited[minIndex] = true;

            for (int v = 0; v < vertexCount; ++v) {
                if (!visited[v] && adjacencyMatrix[minIndex][v] != 0 &&
                    distances[minIndex] != INT_MAX &&
                    distances[minIndex] + adjacencyMatrix[minIndex][v] < distances[v]) {
                    distances[v] = distances[minIndex] + adjacencyMatrix[minIndex][v];
                }
            }
        }
        ofstream outFile(outputFilename);
        if (!outFile) {
            throw runtime_error("Не могу создать файл: " + outputFilename);
        }
        outFile << "Кратчайший путь из вершины " << startVertex << ":\n";
        for (int i = 0; i < vertexCount; ++i) {
            outFile << " к вершине " << i << ": ";
            if (distances[i] == INT_MAX) {
                outFile << "пути нет";
            }
            else {
                outFile << distances[i];
            }
            outFile << "\n";
        }
    };

    friend ostream& operator<<(ostream& os,  ClassGraph& graph) 
    {
        graph.printGraph(os);
        return os;
    };

    ClassGraph& operator=(const ClassGraph& other) {
        if (this != &other) {
            adjacencyMatrix = other.adjacencyMatrix;
            vertexCount = other.vertexCount;
        }
        return *this;
    };
};

