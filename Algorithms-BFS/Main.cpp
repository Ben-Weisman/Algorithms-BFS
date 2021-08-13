#include "InputOutput.h"
#include "Graph.h"


//TODO: adding the runtime function.
  void main()
{
	  Graph g;
	  Graph* h;
	  InpuOutput io;
	  int countOfVertex;
	  countOfVertex = io.getCountOfVertexFromUser();
	  int s = io.getStartVertex(countOfVertex);
	  int t = io.getTargetVertex(countOfVertex);
	  g.MakeEmptyGraph(countOfVertex);
	  g.ReadGraph();
	  h = g.FindShortestPaths(s, t);
	  h->PrintGraph();

	  delete h;

}