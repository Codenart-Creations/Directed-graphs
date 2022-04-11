#include "AdVertexList.h"

// Init AdVertexList
AdVertexList::AdVertexList()
{
	head = nullptr;
	tail = nullptr;
}

// Init AdVertexList with one value
AdVertexList::AdVertexList(runType value)
{
	Node* newNode = new Node;
	newNode->element.nodeLabel = value;
	newNode->element.wasVisited = false;
	newNode->next = nullptr;

	head = newNode;
	tail = newNode;
	length += 1;
}

// Init AdVertexList with AdVertexList = {  }
AdVertexList::AdVertexList(std::initializer_list<runType> values)
{
	for (runType element : values)
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
bool AdVertexList::insert(int index, runType value)
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
bool AdVertexList::push(runType value)
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
bool AdVertexList::append(runType value)
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
bool AdVertexList::deleteAt(int index, runType& value)
{
	bool valid = (index >= 0 && index < length) ? true : false;

	if (valid)
	{
		Node* prev = nullptr;
		Node* trav = head;

		if (index == 0)
		{
			this->pull(value);
		}

		else
		{
			for (int i = 0; i < index; i++)
			{
				prev = trav;
				trav = trav->next;
			}

			value = trav->element.nodeLabel;

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

// Deletes and retrieves value at first index
bool AdVertexList::pull(runType& value)
{
	bool success = (length == 0) ? false : true;

	if (success)
	{
		Node* first = head;
		value = first->element.nodeLabel;
		head = first->next;
		delete first;
		length--;

		if (length == 0)
		{
			head = nullptr;
			tail = nullptr;
		}

	}

	return success;
}

// Deletes first index
runType AdVertexList::pull()
{
	bool success = (length == 0) ? false : true;
	runType value = NULL;

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

// Deletes and returns last index
bool AdVertexList::pop(runType& value)
{
	bool success = (length == 0) ? false : true;

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
	return success;
}

// Deletes last index
runType AdVertexList::pop()
{
	bool success = (length == 0) ? false : true;
	runType value = NULL;

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
std::vector<runType> AdVertexList::returnAdVertexList()
{
	bool success = not isEmpty();
	std::vector<runType> returnArray;

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
runType AdVertexList::getFrom(int index)
{
	bool valid = (index >= 0 && index < length) ? true : false;
	runType value = NULL;

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

// Returns first element, if empty returns NULL
runType AdVertexList::getFirst()
{
	bool success = not isEmpty();
	runType value = NULL;

	if (success)
		value = head->element.nodeLabel;

	return value;
}

// Returns last element, if empty returns NULL
runType AdVertexList::getLast()
{
	bool success = not isEmpty();
	runType value = NULL;

	if (success)
		value = tail->element.nodeLabel;

	return value;
}

//Deletes the element in AdVertexList, if element isnt an adjacent or if list of adjacents is empty, returns false and doesnt run
bool AdVertexList::deleteThis(runType nodeLabel)
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
bool AdVertexList::isAdjacent(runType nodeLabel)
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

// Updates first element, returns false if AdVertexList is empty
bool AdVertexList::updateFirst(int value)
{
	bool success = not isEmpty();

	if (success)
	{
		head->element.nodeLabel = value;
	}

	return success;
}

// Updates last element, returns false if AdVertexList is empty
bool AdVertexList::updateLast(int value)
{
	bool success = not isEmpty();

	if (success)
	{
		tail->element.nodeLabel = value;
	}

	return success;
}
	