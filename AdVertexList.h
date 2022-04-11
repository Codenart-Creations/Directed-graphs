#ifndef AdVertexList_H_INCLUDED
#define AdVertexList_H_INCLUDED

#include <initializer_list>
#include <vector>

typedef int runType;

struct GraphVertex {
    runType nodeLabel;
    bool wasVisited;
};

//struct Node
//{
//    GraphVertex element;
//    Node* next;
//};


struct AdVertexList
{
private:
    struct Node
    {
        GraphVertex element;
        Node* next;
    };
    Node* head;
    Node* tail;
    int length = 0;


public:
    AdVertexList();
    AdVertexList(runType value);
    AdVertexList(std::initializer_list<runType> values);
    bool deleteAdVertexList();

    int len();
    bool isEmpty();

    bool insert(int index, runType value);
    bool push(runType value);
    bool append(runType value);
    
    bool deleteAt(int index, runType &value);
    bool deleteAt(int index);
    bool deleteThis(runType nodeLabel);
    bool pull(runType &value);
    runType pull();
    bool pop(runType &value);
    runType pop();

    std::vector<runType> returnAdVertexList();
    runType getFrom(int index);
    runType getFirst();
    runType getLast();

    bool isAdjacent(runType nodeLabel);
    bool updateAt(int index, int value);
    bool updateFirst(int value);
    bool updateLast(int value);
    
};


#endif // AdVertexList_H_INCLUDED
