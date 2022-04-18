#ifndef AdVertexList_H_INCLUDED
#define AdVertexList_H_INCLUDED

#include <initializer_list>
#include <vector>
#include <string>

struct GraphVertex {
    int nodeLabel;
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
		char VertexName[256];
    Node* head;
    Node* tail;
    int length = 0;


public:
    AdVertexList();
    AdVertexList(int value);
    AdVertexList(std::initializer_list<int> values);
    bool deleteAdVertexList();

    int len();
    bool isEmpty();
		std::string listName();
    bool listName(std::string newName);

    bool insert(int index, int value);
    bool push(int value);
    bool append(int value);
    
    bool deleteAt(int index);
    bool deleteThis(int nodeLabel);
    int pull();
    int pop();

    int getFrom(int index);
    bool updateAt(int index, int value);
    std::vector<int> returnAdVertexList();

    bool isAdjacent(int nodeLabel);
    int getIndexOf(int nodeLabel);
    bool changeVisitState(int index, bool value);
    bool checkVisitState(int index);

    
};


#endif // AdVertexList_H_INCLUDED
