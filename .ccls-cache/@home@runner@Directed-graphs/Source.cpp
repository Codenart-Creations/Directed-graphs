#include <iostream>
#include "DirectedGraphs.h"

using namespace std;

int main()
{
	AdVertexList test(5);
	DirectedGraph tttt;
	if (tttt.addVertex(8))
		cout << "it run\n";

	// tttt.addVertex(8);
	
	cout << test.vertexName() << endl;
	cout << test.len() << "\n";

	test.append(7);

	cout << test.getFirst() << "\n";
	cout << test.len() << "\n";
}