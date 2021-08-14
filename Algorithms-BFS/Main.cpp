#include "InputOutput.h"
#include "Graph.h"
#include <iostream>
#include <chrono>
using namespace std;
/// <summary>
/// This is the maing function of the program. 
/// this function building a graph by giving the number of vertex 
/// (the same value as the max number that aa vertex can be)
/// After that the program getting vertex that called "s"(start), and vertex that called "t"(target),
/// the main purpose is to find the shortest paths by giving serial of edges from the user 
/// (like the others inputs)
/// The system calculate the running time and print it,
///  but befor, it will print all the edges that included in the shortest paths between "s" to "t". 
/// </summary>
int  main()
{

	Graph g;
	Graph* h;
	InpuOutput io;
	int countOfVertex;
	countOfVertex = io.getCountOfVertexFromUser();
	int s = io.getStartVertex(countOfVertex);
	int t = io.getTargetVertex(countOfVertex);
	
	if (s != t) {
		g.MakeEmptyGraph(countOfVertex);
		g.ReadGraph();
		auto start = chrono::high_resolution_clock::now();
		ios_base::sync_with_stdio(false);

		h = g.FindShortestPaths(s, t);

		auto end = chrono::high_resolution_clock::now();

		double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		if (h == nullptr)
		{
			io.printNoPathErrorAndExit();
		}
		else
		{
			io.printGraph(*h);
			io.PrintRunTimeValue(time_taken);
		}

		delete h;
	}
	else {
		io.printIdenticalStartAndEndVertexes();
	}
	return 0;
}