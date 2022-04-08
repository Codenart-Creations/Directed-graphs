#include "DirectedGraphs.h"
#include <iostream>

using namespace std;

//--------------TDA AdVertexList Definition----------------
/*
Creates AdVertexList of adyacency of a specific vertex
*/

// Init AdVertexList
AdVertexList::AdVertexList()
{
	targetVertex = new Node;
	targetVertex->element.nodeLabel = NULL;
	targetVertex->next = adjacentHead;

	adjacentHead = nullptr;
	adjacentTail = nullptr;
	numAdjacent = 0;
}

// Init AdVertexList with a vertex name
AdVertexList::AdVertexList(runType vertexName)
{
	targetVertex = new Node;
	targetVertex->element.nodeLabel = vertexName;
	targetVertex->next = adjacentHead;

	adjacentHead = nullptr;
	adjacentTail = nullptr;
	numAdjacent = 0;
}

// Init list with vertex name and adjacent vertices with (vertexname, {adjacents, })
AdVertexList::AdVertexList(runType vertexName, std::initializer_list<runType> adjacentVertices)
{
	targetVertex = new Node;
	targetVertex->element.nodeLabel = vertexName;
	targetVertex->next = adjacentHead;

	for (runType vertex : adjacentVertices)
		this->append(vertex);
}

// Frees memory used by list, adjacentHead & adjacentTail point to nullptr
bool AdVertexList::deleteList()
{
	while (this->numAdjacent != 0)
	{
	this->pull();	
	}

	return true;
}

// Returns list numAdjacent
int AdVertexList::len()
{
	return numAdjacent;
}

// Returns true if empty
bool AdVertexList::isEmpty()
{
	return (this->len() == 0);
}

// Renames target vertex name
void AdVertexList::vertexName(runType NewVertexName)
{
	targetVertex->element.nodeLabel = NewVertexName;
}

// Returna target vertex name
runType AdVertexList::vertexName()
{
	return targetVertex->element.nodeLabel;
}

//Places element at the end of the list, if index < 0 or index > numAdjacent returns false and doesnt run
bool AdVertexList::insert(int index, runType nodeLabel)
{
	bool valid = (index >= 0 && index < numAdjacent) ? true : false;

	if (valid)
	{
		Node* newNode = new Node;
		newNode->element.nodeLabel = nodeLabel;
		newNode->next = nullptr;

		Node* prev = nullptr;
		Node* trav = adjacentHead;

		if (index == 0)
		{
			this->push(nodeLabel);
		}

		else
		{
			for (int i = 0; i <= index; i++)
			{
				prev = trav;
				trav = trav->next;
			}

			if (trav == nullptr)
			{
				adjacentTail = newNode;
			}

			newNode->next = trav;
			prev->next = newNode;

			numAdjacent++;
		}
	}

	return valid;
}

// Pushes list back and places element at the front
bool AdVertexList::push(runType nodeLabel)
{
	Node* newNode = new Node;
	newNode->element.nodeLabel = nodeLabel;
	newNode->next = adjacentHead;

	if (numAdjacent == 0)
	{
		adjacentTail = newNode;
	}

	adjacentHead = newNode;
	numAdjacent++;

	return true;
}

// Places element at the end of the list
bool AdVertexList::append(runType nodeLabel)
{
	Node* newNode = new Node;
	newNode->element.nodeLabel = nodeLabel;
	newNode->next = nullptr;

	if (numAdjacent == 0)
	{
		adjacentHead = newNode;
		adjacentTail = newNode;
	}
	else
	{
		adjacentTail->next = newNode;
		adjacentTail = newNode;
	}

	numAdjacent++;
	return true;
}

//Deletes element at the end of the list, if index < 0 or index > numAdjacent returns false and doesnt run
bool AdVertexList::deleteAt(int index, runType& returnNodeLabel)
{
	bool valid = (index >= 0 && index < numAdjacent) ? true : false;

	if (valid)
	{
		Node* prev = nullptr;
		Node* trav = adjacentHead;

		if (index == 0)
		{
			returnNodeLabel = this->pull();
		}

		else
		{
			for (int i = 0; i < index; i++)
			{
				prev = trav;
				trav = trav->next;
			}

			returnNodeLabel = trav->element.nodeLabel;

			if (trav == adjacentTail)
			{
				adjacentTail = prev;
				prev->next = nullptr;
			}

			else
			{
				prev->next = trav->next;
			}

			delete trav;
			numAdjacent--;
		}
	}

	return valid;
}

//Deletes element at the end of the list, if index < 0 or index > numAdjacent returns false and doesnt run
bool AdVertexList::deleteAt(int index)
{
	bool valid = (index >= 0 && index < numAdjacent) ? true : false;

	if (valid)
	{
		Node* prev = nullptr;
		Node* trav = adjacentHead;

		if (index == 0)
		{
			this->pull();
		}

		else
		{
			for (int i = 0; i < index; i++)
			{
				prev = trav;
				trav = trav->next;
			}

			if (trav == adjacentTail)
			{
				adjacentTail = prev;
				prev->next = nullptr;
			}

			else
			{
				prev->next = trav->next;
			}

			delete trav;
			numAdjacent--;
		}
	}

	return valid;
}

// Deletes first index
runType AdVertexList::pull()
{
	bool success = (numAdjacent == 0) ? false : true;
	runType nodeLabel = NULL;

	if (success)
	{
		Node* first = adjacentHead;
		adjacentHead = first->next;
		nodeLabel = first->element.nodeLabel;
		delete first;
		numAdjacent--;

		if (numAdjacent == 0)
		{
			adjacentHead = nullptr;
			adjacentTail = nullptr;
		}
	}

	return nodeLabel;
}

// Deletes last index
runType AdVertexList::pop()
{
	bool success = (numAdjacent == 0) ? false : true;
	runType nodeLabel = NULL;

	if (success)
	{
		if (adjacentTail == adjacentHead)
			nodeLabel = this->pull();

		else
		{
			Node* trav = adjacentHead;
			nodeLabel = adjacentTail->element.nodeLabel;

			for (int i = 0; i < this->len() - 2; i++)
			{
				trav = trav->next;
			}

			delete adjacentTail;
			adjacentTail = trav;
			numAdjacent--;
		}

	}
	return nodeLabel;
}

// Returns array of elements in list if list isnt empty
bool AdVertexList::returnList(std::vector<runType>& returnAdVertexList)
{
	bool success = not isEmpty();

	if (success)
	{
		Node* trav = adjacentHead;
		returnAdVertexList.clear();
		for (int i = 0; i < numAdjacent; i++)
		{
			returnAdVertexList.emplace_back(trav->element.nodeLabel);
			trav = trav->next;
		}
	}
	return success;
}

//Returns element from specified index, if index < 0 or index > numAdjacent returns NULL and doesnt run
runType AdVertexList::getFrom(int index)
{
	bool valid = (index >= 0 && index < numAdjacent) ? true : false;
	runType nodeLabel = NULL;

	if (valid)
	{
		Node* trav = adjacentHead;

		if (index == 0)
		{
			nodeLabel = adjacentHead->element.nodeLabel;
		}

		else
		{
			for (int i = 0; i < index; i++)
			{
				trav = trav->next;
			}

			nodeLabel = trav->element.nodeLabel;
		}
	}

	return nodeLabel;
}

// Returns first element, if empty returns NULL
runType AdVertexList::getFirst()
{
	bool success = not isEmpty();
	runType nodeLabel = NULL;

	if (success)
		nodeLabel = adjacentHead->element.nodeLabel;

	return nodeLabel;
}

// Returns last element, if empty returns NULL
runType AdVertexList::getLast()
{
	bool success = not isEmpty();
	runType nodeLabel = NULL;

	if (success)
		nodeLabel = adjacentTail->element.nodeLabel;

	return nodeLabel;
}

// Scans list for nodeLabel, if not found returns false, also returns false if list is empty
bool AdVertexList::isAdjacent(runType nodeLabel)
{
	bool success = not isEmpty();
	bool found = false;

	if (success)
	{
		Node* trav = adjacentHead;
		while (not found && trav != nullptr)
		{
			if (nodeLabel == trav->element.nodeLabel)
				found = true;

			else
				trav = trav->next;
		}
	}

	return found;
}

// Updates element from specified index, if index < 0 or index > numAdjacent returns false and doesnt run
bool AdVertexList::updateAt(int index, runType NewNodeLabel)
{
	bool valid = (index >= 0 && index < numAdjacent) ? true : false;

	if (valid)
	{
		Node* trav = adjacentHead;

		if (index == 0)
		{
			adjacentHead->element.nodeLabel = NewNodeLabel;
		}

		else
		{
			for (int i = 0; i < index; i++)
			{
				trav = trav->next;
			}

			trav->element.nodeLabel = NewNodeLabel;
		}
	}

	return valid;
}

// Updates first element, returns false if list is empty
bool AdVertexList::updateFirst(runType NewNodeLabel)
{
	bool success = not isEmpty();

	if (success)
	{
		adjacentHead->element.nodeLabel = NewNodeLabel;
	}

	return success;
}

// Updates last element, returns false if list is empty
bool AdVertexList::updateLast(runType NewNodeLabel)
{
	bool success = not isEmpty();

	if (success)
	{
		adjacentTail->element.nodeLabel = NewNodeLabel;
	}

	return success;
}


//--------------Directed Graph Definition----------------
/*
Manipulation of AdVertexList vertex, stores each vertex of a directed graph with their adyacency in an array
*/

DirectedGraph::DirectedGraph()
{
	adjacency = nullptr;
	vertexCount = 0;
	maxVertexCount = 0;
}

DirectedGraph::DirectedGraph(int numOfVertex)
{
	adjacency = new AdVertexList[numOfVertex];
	maxVertexCount = numOfVertex;
	vertexCount = 0;
}

// It adds a new vertex to the array by taking a name as a potential vertex name as a parameter
bool DirectedGraph::addVertex(runType vertexName)
{
	bool success = (vertexCount != maxVertexCount) ? true: false;
	
	if (success)
		{
		if (maxVertexCount == 0)
		{
			++maxVertexCount;
			adjacency = new AdVertexList[maxVertexCount];
			adjacency[vertexCount].vertexName(vertexName);
			
			vertexCount++;
		}
	
		else 
		{
			adjacency[vertexCount].vertexName(vertexName);
			vertexCount++;
		}
			
		}
		

	return true;
}


// AdVertexList DirectedGraph::getAdjacentVertices(runType vertexTarget)
// {
// 	for (int of = 0; of < vertexCount; of++)
// 	{
// 		if (adjacency[of].vertexName() == vertexTarget)
// 			return adjacency[of];
// 	}

// 	return NULL;
// }

// bool addAdjacentVertex(int sourceVertex, int targetVertex)
// {
// 	return false;
// }