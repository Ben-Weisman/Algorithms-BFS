#include "Graph.h"
void Graph::MakeEmptyGraph(int numVertices)
{
	m_NeighborsList = new NeighborList(numVertices);

}	