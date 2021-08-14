#include "InputOutput.h"
#include "Graph.h"
#include <iostream>
#include <chrono>
using namespace std;

void main()
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

}