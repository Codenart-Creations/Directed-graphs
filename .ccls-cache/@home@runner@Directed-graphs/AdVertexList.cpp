#include "AdVertexList.h"
#include <iostream>

// Init AdVertexList
AdVertexList::AdVertexList()
{
	VertexName[0] = '0';
	head = nullptr;
	tail = nullptr;
}

// Init AdVertexList with one value
AdVertexList::AdVertexList(int value)
{
	VertexName[0] = '0';
	Node* newNode = new Node;
	newNode->element.nodeLabel = value;
	newNode->element.wasVisited = false;
	newNode->next = nullptr;

	head = newNode;
	tail = newNode;
	length += 1;
}

// Init AdVertexList with AdVertexList = {  }
AdVertexList::AdVertexList(std::initializer_list<int> values)
{
	VertexName[0] = '0';
	for (int element : values)
		this->append(element);
}

// Frees memory used by AdVertexList, head & tail point to nullptr
bool AdVertexList::deleteAdVertexList()
{
	while (this->length != 0)
	{
	this->pull();	
	}

	return true;
}

// Returns AdVertexList length
int AdVertexList::len()
{
	return length;
}

// Returns true if empty
bool AdVertexList::isEmpty()
{
	return (this->len() == 0);
}

//Places element at the end of the AdVertexList, if index < 0 or index > length returns false and doesnt run
bool AdVertexList::insert(int index, int value)
{
	bool valid = (index >= 0 && index < length) ? true : false;

	if (valid)
	{
		Node* newNode = new Node;
		newNode->element.nodeLabel = value;
		newNode->element.wasVisited = false;
		newNode->next = nullptr;

		Node* prev = nullptr;
		Node* trav = head;

		if (index == 0)
		{
			this->push(value);
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
				tail = newNode;
			}

			newNode->next = trav;
			prev->next = newNode;

			length++;
		}
	}

	return valid;
}

// Pushes AdVertexList back and places element at the front
bool AdVertexList::push(int value)
{
	Node* newNode = new Node;
	newNode->element.nodeLabel = value;
	newNode->element.wasVisited = false;
	newNode->next = head;

	if (length == 0)
	{
		tail = newNode;
	}

	head = newNode;
	length++;

	return true;
}

// Places element at the end of the AdVertexList
bool AdVertexList::append(int value)
{
	Node* newNode = new Node;
	newNode->element.nodeLabel = value;
	newNode->element.wasVisited = false;
	newNode->next = nullptr;

	if (length == 0)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}

	length++;
	return true;
}

//Deletes element at the end of the AdVertexList, if index < 0 or index > length returns false and doesnt run
bool AdVertexList::deleteAt(int index)
{
	bool valid = (index >= 0 && index < length) ? true : false;

	if (valid)
	{
		Node* prev = nullptr;
		Node* trav = head;

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

			if (trav == tail)
			{
				tail = prev;
				prev->next = nullptr;
			}

			else
			{
				prev->next = trav->next;
			}

			delete trav;
			length--;
		}
	}

	return valid;
}

// Deletes first index
int AdVertexList::pull()
{
	bool success = (length == 0) ? false : true;
	int value = NULL;

	if (success)
	{
		Node* first = head;
		head = first->next;
		value = first->element.nodeLabel;
		delete first;
		length--;

		if (length == 0)
		{
			head = nullptr;
			tail = nullptr;
		}
	}

	return value;
}

// Deletes last index
int AdVertexList::pop()
{
	bool success = (length == 0) ? false : true;
	int value = NULL;

	if (success)
	{
		if (tail == head)
			value = this->pull();

		else
		{
			Node* trav = head;
			value = tail->element.nodeLabel;

			for (int i = 0; i < this->len() - 2; i++)
			{
				trav = trav->next;
			}

			delete tail;
			tail = trav;
			length--;
		}

	}
	return value;
}

// Returns array of elements in AdVertexList if AdVertexList isnt empty
std::vector<int> AdVertexList::returnAdVertexList()
{
	bool success = not isEmpty();
	std::vector<int> returnArray;

	if (success)
	{
		Node* trav = head;
		returnArray.clear();
		for (int i = 0; i < length; i++)
		{
			returnArray.emplace_back(trav->element.nodeLabel);
			trav = trav->next;
		}
	}
	else
		returnArray = { NULL };

	return returnArray;
}

//Returns element from specified index, if index < 0 or index > length returns NULL and doesnt run
int AdVertexList::getFrom(int index)
{
	bool valid = (index >= 0 && index < length) ? true : false;
	int value = NULL;

	if (valid)
	{
		Node* trav = head;

		if (index == 0)
		{
			value = head->element.nodeLabel;
		}

		else
		{
			for (int i = 0; i < index; i++)
			{
				trav = trav->next;
			}

			value = trav->element.nodeLabel;
		}
	}

	return value;
}

//Deletes the element in AdVertexList, if element isnt an adjacent or if list of adjacents is empty, returns false and doesnt run
bool AdVertexList::deleteThis(int nodeLabel)
{
	bool valid = (not isEmpty()) ? true : false;
	bool found = false;

	if (valid)
	{
		Node* trav = head;

		for (int i = 0; i < length; i++)
		{
			if (trav->element.nodeLabel == nodeLabel)
			{
				found = true;
				this->deleteAt(i);
				length--;
				break;
			}

			else
				trav = trav->next;
		}

	}

	return found;
}

// Scans AdVertexList for nodeLabel, if not found returns false, also returns false if AdVertexList is empty
bool AdVertexList::isAdjacent(int nodeLabel)
{
	bool success = not isEmpty();
	bool found = false;

	if (success)
	{
		Node* trav = head;
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

bool AdVertexList::changeVisitState(int index, bool value)
{
	bool valid = (index >= 0 && index < length) ? true : false;

	if (valid)
	{
		Node* trav = head;

		if (index == 0)
		{
			head->element.wasVisited = value;
		}

		else
		{
			for (int i = 0; i < index; i++)
			{
				trav = trav->next;
			}

			trav->element.wasVisited = value;
		}
	}

	return valid;
}

bool AdVertexList::checkVisitState(int index)
{
	bool valid = (index >= 0 && index < length) ? true : false;
	bool wasVisited = false;

	if (valid)
	{
		Node* trav = head;

		if (index == 0)
		{
			wasVisited = head->element.wasVisited;
		}

		else
		{
			for (int i = 0; i < index; i++)
			{
				trav = trav->next;
			}

			wasVisited = trav->element.wasVisited;
		}
	}

	return wasVisited;
}



int AdVertexList::getIndexOf(int nodeLabel)
{
	bool valid = not isEmpty();
	int value = NULL;

	if (valid)
	{
		Node* trav = head;

		for (int i = 0; i < this->len(); i++)
		{
			if (trav->element.nodeLabel == nodeLabel)
			{
				value = i;
				break;
			}

			trav = trav->next;
		}

	}

	return value;
}

// Updates element from specified index, if index < 0 or index > length returns false and doesnt run
bool AdVertexList::updateAt(int index, int value)
{
	bool valid = (index >= 0 && index < length) ? true : false;

	if (valid)
	{
		Node* trav = head;

		if (index == 0)
		{
			head->element.nodeLabel = value;
		}

		else
		{
			for (int i = 0; i < index; i++)
			{
				trav = trav->next;
			}

			trav->element.nodeLabel = value;
		}
	}

	return valid;
}

bool AdVertexList::listName(std::string newName)
{
	for (int i = 0; i < newName.length(); i++)
		{
		VertexName[i] = newName[i];
			
		}
	VertexName[newName.length()] = '\0';
	
	return true;
}

std::string AdVertexList::listName()
{
	return VertexName;
}