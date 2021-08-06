#ifndef __GRAPH_H
#define __GRAPH_H
#include "Vertex.h"
#include "Edge.h"
#include "NeighborList.h"

class Graph
{
private:
	int m_numVertices;
	int m_numEdges;
	NeighborList* m_NeighborsList;
	
public:
	/*
	* Creates empty graph with n vertices.
	* @param: number of vertices in the graph.
	*/
	void MakeEmptyGraph(int numVertices);

	/*
	* Retunrs true if the given edge is exists in the graph. Else false.
	* @params: vertex v, vertex u for representing the edge.
	*/
	bool IsAdjacent(Vertex v, Vertex u);
	Vertex* getAdjList(Vertex u);
	void AddEdge(Vertex u, Vertex v);
	void RemoveEdge(Vertex u, Vertex v);
	void ReadGraph();
	void PrintGraph();
	int IsEmpty();
	int AddEdge(int i, int j);
	Edge* Adj(int i);
	
};

#endif // !__GRAPH_H