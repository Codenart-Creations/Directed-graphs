#include "DirectedGraphs.h"
#include <iostream>

using namespace std;

//--------------Directed Graph Definition----------------
/*
Manipulation of AdVertexList vertex, stores each vertex of a directed graph with their adyacency in an array
*/

DirectedGraph::DirectedGraph()
{
	adjacency = nullptr;
	maxVertexCount = 0;
}

DirectedGraph::DirectedGraph(int numOfVertex)
{
	adjacency = new AdVertexList[numOfVertex];

	maxVertexCount = numOfVertex;
}

// If vertex target is larger than vertex count or smaller than 0, it means vertex target does exist
 bool DirectedGraph::addAdjacentVertex(int vertexTarget, runType adjacentVertex)
 {
	 bool success = ((0 < vertexTarget && vertexTarget <= maxVertexCount) && (0 < adjacentVertex && adjacentVertex <= maxVertexCount));
	
	 if (success)
		 adjacency[vertexTarget - 1].append(adjacentVertex);
	
	return success;
 }

 // If vertex target is larger than vertex count or smaller than 0, it means vertex target does exist
 bool DirectedGraph::delAdjacentVertex(int vertexTarget, runType adjacentVertex)
 {
	 bool success = ((0 < vertexTarget && vertexTarget <= maxVertexCount) && (0 < adjacentVertex && adjacentVertex <= maxVertexCount));
	 bool accomplished = false;

	 if (success)
		accomplished = adjacency[vertexTarget - 1].deleteThis(adjacentVertex);
	
	return accomplished;
 }

// Returns a list of all adjacent vertices
 std::vector<runType> DirectedGraph::getAdjacentVertices(runType vertexTarget)
 {
	 bool success = ((0 < vertexTarget && vertexTarget <= maxVertexCount));
	 std::vector<runType> accomplished = { NULL };

	 if (success)
		 accomplished = adjacency[vertexTarget].returnAdVertexList();

	 return accomplished;
 }

// Checks if vertex 2 is connected to vertex 1, if vertex 1 or vertex 2 doesnt exist, it returns false, returns true if connected v1->v2
bool DirectedGraph::areConnected(int vertex1, int vertex2)
{
	bool success = ((0 < vertex1 && vertex1 <= maxVertexCount) && (0 < vertex2 && vertex2 <= maxVertexCount));
	bool accomplished = false;

	if (success)
		accomplished = adjacency[vertex1 - 1].isAdjacent(vertex2);

	return accomplished;
}
