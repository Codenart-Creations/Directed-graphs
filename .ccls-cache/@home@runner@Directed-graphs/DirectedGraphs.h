#ifndef DIRECTEDGRAPHS_H_INCLUDED
#define DIRECTEDGRAPHS_H_INCLUDED

#include <initializer_list>
#include <vector>
#include <string>

// Type of label to be used ( int )
typedef int runType;

struct GraphVertex {
    runType nodeLabel;
    bool wasVisited;
};

struct AdVertexList
{
private:
    struct Node
    {
        GraphVertex element;
        Node* next;
    };

    Node* targetVertex;
    Node* adjacentHead;
    Node* adjacentTail;
    int numAdjacent = 0;


public:
    AdVertexList();
    AdVertexList(runType vertexName);
    AdVertexList(runType vertexName, std::initializer_list<runType> adjacentVertices);
    bool deleteList();

    int len();
    bool isEmpty();
    void vertexName(runType newVertexName);
    runType vertexName();

    bool insert(int index, runType vertexName);
    bool push(runType vertexName);
    bool append(runType vertexName);
    
    bool deleteAt(int index, runType &returnNodeLabel);
    bool deleteAt(int index);
    runType pull();
    runType pop();

    bool returnList(std::vector<runType> &returnAdVertexList);
    runType getFrom(int index);
    runType getFirst();
    runType getLast();

    bool isAdjacent(runType nodeLabel);
    bool updateAt(int index, runType NewNodeLabel);
    bool updateFirst(runType NewNodeLabel);
    bool updateLast(runType NewNodeLabel);

};

    struct DirectedGraph {
    private:
        AdVertexList* adjacency; // El arreglo de la lista de adyacencia debe ser inicializado dinamicamente
        int maxVertexCount;
        int vertexCount;

    public:
        DirectedGraph(); //costructor por defecto
        DirectedGraph(int vertexCount); // constructor parametrizado
        // ~DirectedGraph(); //destructor
				
				bool addVertex(runType vertexName);
				
        bool addAdjacentVertex(int sourceVertex, runType targetVertex); //Esta funci�n agrega un nuevo v�rtice adyacente al v�rtice cuyo �ndice se pasa como primer par�metro
        bool removeAdjacentVertex(int sourceVertex, runType removedVertex); //Esta funci�n elimina un v�rtice adyacente (removedVertex) del v�rtice cuyo �ndice se pasa como primer par�metro
        bool areConnected(int vertex1, int vertex2); //Determina si dos v�rtices/nodos (cuyos �ndices se pasan como paratemtros) son adyacentes
        AdVertexList getAdjacentVertices(runType vertexTarget); //Esta funci�n devuelve una lista ligada que contiene los nodos vecinos del nodo cuyo v�rtice se pasa como par�metro
        //Esta funcion no necesariamente tiene que estar el el archivo de cabecera
        //donde se declara la estructura que denota el TDA de grafo dirigido
        bool containsCycle(DirectedGraph& g, std::string& cyclePath);

    };
    


#endif // DIRECTEDGRAPHS_H_INCLUDED
