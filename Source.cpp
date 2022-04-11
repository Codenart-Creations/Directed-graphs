#include <iostream>
#include "DirectedGraphs.h"

using namespace std;

int main()
{
	AdVertexList test = { 0, 5 , 3 };
	 std::vector<runType> lol;
	 DirectedGraph tttt(10);
	 tttt.addAdjacentVertex(0, 9);
	 tttt.addAdjacentVertex(0, 7);
	 lol =  tttt.getAdjacentVertices(1);

	 cout << lol[0];
	 //cout << "\n" << tttt.areConnected(0, 9);
	/*
	cout << test.len() << "\n";

	test.append(6);

	cout << test.getFirst() << "\n";
	cout << test.len() << "\n";

  test.append(8);
vector<int> a;
	cout << test.getLast() << "\n";
	cout << test.len() << "\n";

  */
  
}