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
    // ~DirectedGraph(); //destructor

    bool addAdjacentVertex(int targetVertex, runType adjacentVertex); 
    bool delAdjacentVertex(int targetVertex, runType vertexToRemove);
    std::vector<runType> getAdjacentVertices(runType vertexTarget); 

    bool areConnected(int vertex1, int vertex2);
        
    bool containsCycle(DirectedGraph& g, std::string& cyclePath);

};
    


#endif // DIRECTEDGRAPHS_H_INCLUDED
