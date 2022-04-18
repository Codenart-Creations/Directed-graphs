#include "DirectedGraphs.h"
#include <iostream>

using namespace std;

//--------------Directed Graph Definition----------------
/*
Manipulation of AdVertexList vertex, stores each vertex of a directed graph with their adyacency in an array
*/

// Default constructor
DirectedGraph::DirectedGraph()
{
	adjacency = nullptr;
	maxVertexCount = 0;
}

// Inits directed graph with a fixed set number of vertices
DirectedGraph::DirectedGraph(int numOfVertex)
{
	adjacency = new AdVertexList[numOfVertex];
	
	maxVertexCount = numOfVertex;
}

// Inits directed graph with its vertices and their adjacencies, automatically setting max vertex count size
DirectedGraph::DirectedGraph(std::initializer_list<AdVertexList> values)
{
	int count = 0;
	for (AdVertexList element : values)
		count++;

	adjacency = new AdVertexList[count];
	maxVertexCount = count;

	int i = 0;
	for (AdVertexList element : values)
	{
		adjacency[i] = element;
		i++;
	}
}

DirectedGraph::~DirectedGraph()
{
	bool success = (maxVertexCount > 0);

	if (success)
	{
		for (int i = 0; i < maxVertexCount; ++i)
		{
			adjacency[i].deleteAdVertexList();
		}
	}

	delete adjacency;

}

// If vertex target is larger than vertex count or smaller than 0, it means vertex target does exist
 bool DirectedGraph::addAdjacentVertex(int vertexTarget, int adjacentVertex)
 {
	 bool success = ((0 < vertexTarget && vertexTarget <= maxVertexCount) && (0 < adjacentVertex && adjacentVertex <= maxVertexCount));
	 
	 if (success)
	 {
		 if (adjacency[vertexTarget - 1].isAdjacent(adjacentVertex))
			 success = false; // vertex to be addded is already in adjacency list of target vertex

		 else
			 adjacency[vertexTarget - 1].append(adjacentVertex);
	 }
	
	return success;
 }

 // If vertex target is larger than vertex count or smaller than 0, it means vertex target does exist
 bool DirectedGraph::delAdjacentVertex(int vertexTarget, int adjacentVertex)
 {
	 bool success = ((0 < vertexTarget && vertexTarget <= maxVertexCount) && (0 < adjacentVertex && adjacentVertex <= maxVertexCount));
	 bool accomplished = false;

	 if (success)
		accomplished = adjacency[vertexTarget - 1].deleteThis(adjacentVertex);
	
	return accomplished;
 }

// Returns a list of all adjacent vertices, if vertex doesnt exist, returns 0
 AdVertexList DirectedGraph::getAdjacentVertices(int vertexTarget)
 {
	 bool success = ((0 < vertexTarget && vertexTarget <= maxVertexCount));
	 AdVertexList accomplished;

	 if (success)
		 accomplished = adjacency[vertexTarget - 1];

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


bool DirectedGraph::updateToVisited(int vertexTarget, int adjacentVertex)
{
	bool success = ((0 < vertexTarget && vertexTarget <= maxVertexCount) && (0 < adjacentVertex && adjacentVertex <= maxVertexCount));
	bool accomplished = false;

	if (success)
	{
		AdVertexList vertex = adjacency[vertexTarget - 1];
		accomplished = vertex.changeVisitState(vertex.getIndexOf(adjacentVertex), true);
	}

	return accomplished;
}

bool DirectedGraph::updateToUnvisited(int vertexTarget, int adjacentVertex)
{
	bool success = ((0 < vertexTarget && vertexTarget <= maxVertexCount) && (0 < adjacentVertex && adjacentVertex <= maxVertexCount));
	bool accomplished = false;

	if (success)
	{
		AdVertexList vertex = adjacency[vertexTarget - 1];
		accomplished = vertex.changeVisitState(vertex.getIndexOf(adjacentVertex), false);
	}

	return accomplished;
}

bool DirectedGraph::checkIfVisited(int targetVertex, int adjacentVertex)
{
	bool success = ((0 < targetVertex && targetVertex <= maxVertexCount) && (0 < adjacentVertex && adjacentVertex <= maxVertexCount));
	bool wasVisited = false;

	if (success)
	{
		AdVertexList vertex = adjacency[targetVertex - 1];
		wasVisited = vertex.checkVisitState(vertex.getIndexOf(adjacentVertex));
	}

	return wasVisited;
}

bool DirectedGraph::wereAllVisited(int targetVertex)
{
	bool success = (0 < targetVertex && targetVertex <= maxVertexCount);
	bool AllWereVisited = false;
	if (success)
	{
		int NUMAD = adjacency[targetVertex - 1].len();
		AllWereVisited = true; // if vertex has no adjacents, then all adjacents were tecnically visited
		
		for (int i = 0; i < NUMAD; i++)
		{
			AllWereVisited = adjacency[targetVertex - 1].checkVisitState(i);

			if (not AllWereVisited)
			{
				AllWereVisited = false;
				break;
			}
			
		}
	}
	return AllWereVisited;
}

bool DirectedGraph::nameAllVertex()
{
	bool success = (maxVertexCount > 0);

	if (success)
	{
		for (int i = 1; i <= maxVertexCount; i++)
	{
		renameVertex(i, to_string(i));
		}
		}

	return success;
}

bool DirectedGraph::nameAllVertex(char character)
{
	bool success = (maxVertexCount > 0);

	std::string tt;
	int ch = character;
	tt = character;
	char c;
	
	if (success)
	{
		for (int i = 1; i <= maxVertexCount; i++)
		{
		renameVertex(i, tt);
		c = char(++ch);
		tt = c;
		}
	}

	return success;
}



std::string DirectedGraph::getVertexName(int vertex)
{
	bool success = ((0 < vertex && vertex <= maxVertexCount));
	std::string vertexLabel = "0";

	if (success)
	{
		vertexLabel = adjacency[vertex - 1].listName();
	}

	return vertexLabel;
}

bool DirectedGraph::renameVertex(int vertex, std::string newName)
{
	bool success = ((0 < vertex && vertex <= maxVertexCount));

	if (success)
	{
		adjacency[vertex - 1].listName(newName);
	}

	return success;
}

int DirectedGraph::numOfVertex()
{
	return maxVertexCount;
}

bool DirectedGraph::clearAllVisited()
{
  for(int i=1; i<=numOfVertex(); i++ )
    {
      AdVertexList vertex = getAdjacentVertices(i);
      for(int j = 0; j < vertex.len(); j++)
        {
          updateToUnvisited(i,vertex.getFrom(j));
          
        }
    }
    
    return true;
}