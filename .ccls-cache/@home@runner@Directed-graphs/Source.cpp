#include <iostream>
#include "DirectedGraphs.h"
#include <stack>

using namespace std;

bool containsCycleIter(DirectedGraph& g, std::string& cyclePath);
bool containsCycleRecur(DirectedGraph& G, std::string& cyclePath);
void printPath(DirectedGraph& DGraph, string path);
bool findCycle(DirectedGraph& DGraph);

void printDirectedGraph(DirectedGraph& DGraph);

enum ALPHABET {a = 1, b, c, d, e, f, g,h, i};

int main()
{
	// POSITIVE TEST 1

   AdVertexList P1Va = {b,d};
	 AdVertexList P1Vb = {d, e};
	 AdVertexList P1Vc = {a};
	 AdVertexList P1Vd = {c, e, f, g};
	 AdVertexList P1Ve = {g};
	 AdVertexList P1Vf = {c};
   AdVertexList P1Vg = {};
   DirectedGraph Pos1 = {P1Va, P1Vb, P1Vc, P1Vd, P1Ve, P1Vf, P1Vg};
	 Pos1.nameAllVertex('a'); // Names all vertices starting with a

	
  // POSITIVE TEST 2
  
   AdVertexList P2V1 = {};
	 AdVertexList P2V2 = {1,4};
	 AdVertexList P2V3 = {2, 6};
	 AdVertexList P2V4 = {3, 5, 6};
	 AdVertexList P2V5 = {1};
	 AdVertexList P2V6 = {1, 2, 5};
   DirectedGraph Pos2 = {P2V1, P2V2, P2V3, P2V4, P2V5, P2V6};
	 Pos2.nameAllVertex();  // Names all vertices starting with 1

  // POSITIVE TEST 3

   AdVertexList P3V1 = {2,3};
	 AdVertexList P3V2 = {4}; 
	 AdVertexList P3V3 = {9};
	 AdVertexList P3V4 = {5,7};
	 AdVertexList P3V5 = {3,7};
	 AdVertexList P3V6 = {2,7};
   AdVertexList P3V7 = {8,9};
	 AdVertexList P3V8 = {6,9};
   AdVertexList P3V9 = {};
   DirectedGraph Pos3 = {P3V1, P3V2, P3V3, P3V4, P3V5, P3V6,P3V7,P3V8,P3V9};
	 Pos3.nameAllVertex(); // Names all vertices starting with 1

 
  // NEGATIVE TEST 1
  
    AdVertexList N1Va = {b, c};
	  AdVertexList N1Vb = {d, e};
	  AdVertexList N1Vc = {e, f};
	  AdVertexList N1Vd = {};
	  AdVertexList N1Ve = {};
	  AdVertexList N1Vf = {};
    DirectedGraph Neg1 = {N1Va, N1Vb, N1Vc, N1Vd, N1Ve, N1Vf};
	  Neg1.nameAllVertex('a'); 
  
  //NEGATIVE TEST 2
  
    AdVertexList N2V2 = {};
	  AdVertexList N2V3 = {5,7};
	  AdVertexList N2V5 = {8};
	  AdVertexList N2V7 = {5,8};
	  AdVertexList N2V8 = {6};
	  AdVertexList N2V9 = {}; 
    AdVertexList N2V10 = {};   
	  AdVertexList N2V11= {1,6,7};
  
    N2V2.listName("2");
    N2V3.listName("3");
    N2V5.listName("5");
    N2V7.listName("7");
    N2V8.listName("8");
    N2V9.listName("9"); 
    N2V10.listName("10");
    N2V11.listName("11");
    DirectedGraph Neg2 = {N2V2, N2V3, N2V5, N2V7, N2V8, N2V9, N2V10, N2V11};
	
  //NEGATIVE TEST 3

	  AdVertexList N3V1 = {2};
	  AdVertexList N3V2 = {3,4};
	  AdVertexList N3V3 = {4,5,6};
	  AdVertexList N3V4 = {6};
	  AdVertexList N3V5 = {};
	  AdVertexList N3V6 = {};
    DirectedGraph Neg3 = {N3V1, N3V2, N3V3, N3V4, N3V5, N3V6};
	  Neg3.nameAllVertex(); 


	char menu = '1';
	char run = 'y';
	
	cout << "\nEste programa verifica si un grapho dirigido tiene\n"
		      "un ciclo Haciendo uso de recursion y de la iteracion\n\n";
	
	
	while(run != 'n')
	{
		cout << "\n~Menu~\n1. Casos de prueba \n2. Prueba Nueva\n#.Salir";
		cout << "\n#: ";
		cin >> menu;
		
		if (menu == '1') // casos de prueba
		{
			cout << "\n-----------------------------\n";
			cout << "\n~Desplegando casos de prueba~\n";
			
			cout << "\nCaso Positiva 1";
			printDirectedGraph(Pos1);
			findCycle(Pos1);

			cout << "\n-----------------------------\n";

			cout << "\nCaso Positiva 2";
			printDirectedGraph(Pos2);
			findCycle(Pos2);

			cout << "\n-----------------------------\n";

			cout << "\nCaso Positiva 3";
			printDirectedGraph(Pos3);
			findCycle(Pos3);

			cout << "\n-----------------------------\n";

			cout << "\nCaso Negativo 1";
			printDirectedGraph(Neg1);
			findCycle(Neg1);


			cout << "\n-----------------------------\n";

			cout << "\nCaso Negativo 2";
			printDirectedGraph(Neg2);
			findCycle(Neg2);
		 
			cout << "\n-----------------------------\n";
			
			cout << "\nCaso Negativo 3";
			printDirectedGraph(Neg3);
			findCycle(Neg3);
		
			cout << "\n-----------------------------\n";
		}
	
		else if (menu == '2')
		{
			char subMenu = '0';
			char run = 'y';

			while (run != 'n')
			{
				int NUMVERTEX = 0;
				cout << "\nCuantos Vertices tendra el grapho: ";
				cin >> NUMVERTEX;

				NUMVERTEX = (NUMVERTEX == 1) ? 2: NUMVERTEX; // Minimun size is 2
				
				DirectedGraph grapho(NUMVERTEX);
				grapho.nameAllVertex();
				
				char subRun = 'y';
				while(subRun != 'n')
				{
					cout << "\n-----------------------------\n";
					cout << "\n~Grapho~";
					printDirectedGraph(grapho);
					
					cout << "\n1. Buscar Ciclos \n2. Agregar Vertice Adjacente"
						"\n3.Quitar Vertice Adjacente \n4. Crear Otro \n#. Salir\n#: ";
					cin >> subMenu;
	
					if (subMenu == '1') // buscar ciclos
					{
						cout << "\n~Buscando Ciclos~\n";
				
						printDirectedGraph(grapho);
						findCycle(grapho);
					}
	
					else if (subMenu == '2') // agregar ad
					{
						char subMenRun = 'y';
						short vertice;
						short verticeAdj;
	
						while (subMenRun != 'n')
					  {
							printDirectedGraph(grapho);
							cout << "\nA cual vertice: ";
							cin >> vertice;
							
							cout << "\nNuevo adjacente sera: ";
							cin >> verticeAdj;

							if (vertice == verticeAdj)
							{
								cout << "\n~Error~\n";
								cout << "\nVertice no puede ser adjacente a si misma\n";
								
								cout << "\nIntentar Otra Vez?\ty/n\n#: ";
								cin >> subMenRun;
							}
							
							else if (grapho.addAdjacentVertex(vertice, verticeAdj))
							{
								cout << "\n~Vertice Adjacente Agregado~\n";
								subMenRun = 'n';
							}
		
							else
							{
								cout << "\n~Error~\n";
								cout << "\nAsegura introducir un numero y que sea de la lista de vectores\n";
								
								cout << "\nIntentar Otra Vez?\ty/n\n#: ";
								cin >> subMenRun;
								
							}
						
						}
					
					}
						
					else if (subMenu == '3') // borrar ad
					{
						char subMenRun = 'y';
						short vertice;
						short verticeAdj;
	
						while (subMenRun != 'n')
					  {
							printDirectedGraph(grapho);
							cout << "\nA cual vertice: ";
							cin >> vertice;
							
							cout << "\nAdjacente a borrar: ";
							cin >> verticeAdj;
							
							if (grapho.delAdjacentVertex(vertice, verticeAdj))
							{
								cout << "\n~Vertice Adjacente Borrado~\n";
								subMenRun = 'n';
							}
		
							else
							{
								cout << "\n~Error~\n";
								cout << "\nAsegura introducir un numero y que sea de la lista de vectores\n";
								
								cout << "\nIntentar Otra Vez?\ty/n\n#: ";
								cin >> subMenRun;
								
							}
						
						}
					
					}
	
					else if (subMenu == '4') // crear otro grapho
					{
						cout << "\n~Creando Grapho~\n";
						
						subRun = 'n';
					}
	
					else
					{
						subRun = 'n';
						run = 'n';
					}
				
				}
			}			
		}

		else // exit
			break;

		}// w

		cout << "\n\n~Terminando session~\n\n";

}//m


//Funcion Recursiva
//LOS -48 son para convertir los numeros de char a int 
bool containsCycleRecur(DirectedGraph& G, std::string& cyclePath)
{
  int SIZE = cyclePath.length();
  AdVertexList temp = G.getAdjacentVertices( cyclePath[SIZE-1]-48);

  //Si no encuentra nodos adyacentes se devuelve un paso
  if(temp.isEmpty())
  {
    int SIZE = cyclePath.length();
    
    G.updateToUnvisited(cyclePath[SIZE-2]-48, cyclePath[SIZE-1]-48);       
    cyclePath.erase(SIZE-1, 1); 
    
    return false;    
  }

  //Aqui se llama cada nodo adyacente para repetir el proceso
  for(int i = 0; i<temp.len(); i++)
  {       
      if(G.checkIfVisited(cyclePath[SIZE-1]-48, temp.getFrom(i)))    
      {
      while(cyclePath[0]!=cyclePath[cyclePath.length()-1])
        cyclePath.erase(0, 1); 
          return true;
        }
      else
      {
          G.updateToVisited(cyclePath[SIZE-1]-48, temp.getFrom(i));
          cyclePath= (cyclePath + to_string(temp.getFrom(i)));  
				
          if(containsCycleRecur(G,cyclePath))
          {
            while(cyclePath[0]!=cyclePath[cyclePath.length()-1])
        cyclePath.erase(0, 1); 
              return true;
            }
      }  
  }  

  //Si no hay nodos adyacentes no explorados se devuelve un paso
  //SIZE = cyclePath.length();
      
G.updateToUnvisited(cyclePath[SIZE-2]-48, cyclePath[SIZE-1]-48);
  
  cyclePath.erase(SIZE-1, 1); 
  return false;  
}

/*
idea: 

1. se guarda el vector inicial <origin>
2. si no tiene vector adjacentes 
   retorna falso

3. se asigna el primer vertor adjacente a <source>
4. se asigna el primer adjacente de source a <targetVertex>
5. Si target vertex cumple uno de lo listado, o se devuelve, retorna true o se asigna target verte como <source> si tiene adjacente sin explorar

5.1 si targetVertex tiene ad sin explorar, se asigna como source y se vuelve desde 4
5.2 si se retrocede, se incrementa el contador y se asigna el siguiente adjacente a <targetertex>
5.2.1 se repite hasta que se encuentre un nuevo <source> o se explora cada adjacente
5.3 si se explora cad adjacente, retrocede por no ser un nuevo source

5.3.1 al retroceder al source anterior, se vuelve a mirar cada adjacente pero salta vectores ya explorados
5.3.2 si explora cada adjacente y no encuentra un <source> nuevo, retrocede el source al anterior de esa

algo asi

*/

bool containsCycleIter(DirectedGraph& g, std::string& cyclePath)
{
	AdVertexList originVertex; // vertice inicial
	AdVertexList sourceVertex; // vertice observado
	AdVertexList targetVertex; // vertice adjacente del vertice observado
	
	bool CycleNotFound = false;
	
	stack<int> path;

	path.push(cyclePath[0] - 48);
	int origin = path.top();

	originVertex = g.getAdjacentVertices(origin);

	if (originVertex.len() > 0) // if origin has no adjacents, cycle is imposible
	{
		bool newSource = false;
		for (int i = 0; i < originVertex.len(); i++) // Cyles adjacents in origin
		{
			path.push(originVertex.getFrom(i));
			
			if (g.getAdjacentVertices(path.top()).len()) // if target vertex isnt empty step forward
			{

				while (path.top() != origin ) // exits if all adjacents of a targeted adjacent of origin has been seen
				{

					int source = path.top();  // assigns a targeted adjacent of origin to start, then reassigns itself to  every new source
					sourceVertex = g.getAdjacentVertices(source);

					int j = 0;
					newSource = false;
					while (sourceVertex.len() > j && not newSource) // exits if a new source is assigned (vertex with untraveled adjacents) or if all adjacents have been seen
					{
		//cout << "\nit entered\n";
						path.push(sourceVertex.getFrom(j));
						// cout << path.top() << "\n"; ---------------------------------------
						int targetAd = path.top(); // assigns a targeted adjacent of source, reassins to every other adjacent of source every cycle
						targetVertex = g.getAdjacentVertices(targetAd);

						if (origin == targetAd) // if initial vertex and last traveled to vertex are the same, theres a cycle
						{
							stack<int> truePath;
							int size =  path.size();
							for (int n = 0; n < size; n++)
							{
							truePath.push(path.top());
							path.pop();
							}
							cyclePath.clear();
							for (int p = 0; p < size; p++)
							{
								cyclePath.append(to_string(truePath.top()));
								truePath.pop();
							}
							
							return true;
						}


						else if (g.checkIfVisited(source, targetAd)) //if target has been seen before, stepback
						{
							path.pop();
							j++;
						}
							
						else if (targetVertex.isEmpty()) // if target doesnt have adjacents, stepback
						{
							g.updateToVisited(source, targetAd);
							path.pop();
							j++;
						}

						else // if target has unexplored adjacents, assign as new source
						{
							g.updateToVisited(source, targetAd);

							newSource = true;

						}

					} // target while


					if (newSource == false) // if a new source wasnt assigned, it means all vertices were traveled to so stepback
					{
						path.pop();
					}

				}// source while

				g.clearAllVisited(); // resets all vertices to unvisited

			} // if target vertex is empty  \/ 

			else // if empty stepback
				path.pop();


		} // for loop origin

	} // if origin empty then cicle is impossible
	
	return CycleNotFound; 
}

// Prints all vertices and their adjacents
void printDirectedGraph(DirectedGraph& DGraph)
{
	AdVertexList vertex;
	cout << endl;
	for (int i = 1; i <= DGraph.numOfVertex(); i++) // Vertices
	{
		vertex = DGraph.getAdjacentVertices(i);
		cout << "V" << vertex.listName() << ": ";
		
		for (int j = 0; j < vertex.len(); j++) // Adjacents
		{
				cout << DGraph.getVertexName(vertex.getFrom(j));
			  cout << ", ";
		}
		cout << endl;
	}
}

// Prints path taken for cycle
void printPath(DirectedGraph& DGraph, string path)
{
	cout << endl << "Camino: ";
	cout<< DGraph.getVertexName(path[0] - 48);
  for(int i=1; i<path.length(); i++)
	  cout<<"->"<< DGraph.getVertexName(path[i] - 48);
}

// Calls upon containsCycleRecur and containsCycleIter to look for a cycle anywhere in the directed graph, if it finds one, calls printPath and returns true
bool findCycle(DirectedGraph& DGraph)
{
	string cyclePath;
	bool cycle = false;
	
	cout<< endl << "Recursivo: ";
	for(int i=1; i < DGraph.numOfVertex(); i++) // visits all veertices as a starting point
  {
    DGraph.clearAllVisited();// resets visit state of graph incase of residue from the function
    cyclePath = to_string(i);
  
		if(containsCycleRecur(DGraph, cyclePath)) // exits on the first cycle it finds
		{
    	cycle = true;
			break;
		}  
  }

	if(cycle)
  {
   cout << "Hay ciclo";
    printPath(DGraph, cyclePath);
  }
  else
    cout << "No hay ciclo";

//----------------------------------------------
	cout << endl;
	cycle = false;

	cout << endl << "Iterativo: ";
	for(int i=1; i < DGraph.numOfVertex(); i++) // visits all veertices as a starting point
	{
	    DGraph.clearAllVisited(); // resets visit state of graph incase of residue from the function
	    cyclePath = to_string(i);
		
	  if(containsCycleIter(DGraph, cyclePath))// exits on the first cycle it finds
	  {    
	  	cycle = true;
	    break;
	  }
	    
	}
	
	if(cycle)
	{
	 cout << "Hay ciclo";
	 printPath(DGraph, cyclePath);
	}
	else
		cout << "No hay ciclo";

	cout << endl;

	return cycle;
}