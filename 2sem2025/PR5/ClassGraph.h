#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <climits>
#include <stdexcept>

class ClassGraph {
public:
    std::vector<std::vector<int>> adjacencyMatrix;

    ClassGraph() : vertexCount(0) {}
    ~ClassGraph() = default;

    int vertexCount;

    void DFSRecursive(int vertex, std::vector<bool>& visited, std::vector<int>& traversalOrder)
    {
        visited[vertex] = true;
        traversalOrder.push_back(vertex);

        for (int i = 0; i < vertexCount; ++i) {
            if (adjacencyMatrix[vertex][i] != 0 && !visited[i]) {
                DFSRecursive(i, visited, traversalOrder);
            }
        }
    };

    void loadFromAdjacencyMatrix(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            throw std::runtime_error("Unable to open file: " + filename);
        }

        file >> vertexCount;
        adjacencyMatrix.resize(vertexCount, std::vector<int>(vertexCount));

        for (int i = 0; i < vertexCount; ++i) {
            for (int j = 0; j < vertexCount; ++j) {
                file >> adjacencyMatrix[i][j];
            }
        }
    };
    void printGraph(std::ostream& os)
    {
        std::vector<bool> visited(vertexCount, false);
        std::vector<int> traversalOrder;

        for (int i = 0; i < vertexCount; ++i) {
            if (!visited[i]) {
                const_cast<ClassGraph*>(this)->DFSRecursive(i, visited, traversalOrder);
            }
        }
        os << "Graph traversal (DFS recursive): ";
        for (int v : traversalOrder) {
            os << v << " ";
        }
        os << "\n";
    };
    void findShortestPaths(int startVertex, const std::string& outputFilename)
    {
        std::vector<int> distances(vertexCount, INT_MAX);
        std::vector<bool> visited(vertexCount, false);
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

        std::ofstream outFile(outputFilename);
        if (!outFile) {
            throw std::runtime_error("Unable to create output file: " + outputFilename);
        }

        outFile << "Shortest paths from vertex " << startVertex << ":\n";
        for (int i = 0; i < vertexCount; ++i) {
            outFile << "To vertex " << i << ": ";
            if (distances[i] == INT_MAX) {
                outFile << "No path";
            }
            else {
                outFile << distances[i];
            }
            outFile << "\n";
        }
    };

    friend std::ostream& operator<<(std::ostream& os,  ClassGraph& graph) 
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

