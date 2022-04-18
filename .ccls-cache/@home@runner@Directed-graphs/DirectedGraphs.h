#ifndef DIRECTEDGRAPHS_H_INCLUDED
#define DIRECTEDGRAPHS_H_INCLUDED

#include "AdVertexList.h"
#include <string>

struct DirectedGraph {
private:
    AdVertexList *adjacency; // Arreglo de listas
    int maxVertexCount;

public:
    DirectedGraph(); //costructor por defecto
    DirectedGraph(int vertexCount); // constructor parametrizado
    DirectedGraph(std::initializer_list<AdVertexList> values);
    ~DirectedGraph(); //destructor

    bool addAdjacentVertex(int targetVertex, int adjacentVertex); 
    bool delAdjacentVertex(int targetVertex, int vertexToRemove);
    AdVertexList getAdjacentVertices(int vertexTarget);
    bool areConnected(int vertex1, int vertex2);
    bool updateToVisited(int targetVertex, int adjacentVertex);
    bool updateToUnvisited(int targetVertex, int adjacentVertex);
    bool checkIfVisited(int targetVertex, int adjacentVertex);
    bool wereAllVisited(int targetVertex);
    std::string getVertexName(int vertex);
		bool renameVertex(int vertex, std::string newName);
		bool nameAllVertex(char character);
		bool nameAllVertex();
    int numOfVertex();

    bool clearAllVisited();

};
    


#endif // DIRECTEDGRAPHS_H_INCLUDED
