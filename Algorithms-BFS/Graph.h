#ifndef __GRAPH_H
#define __GRAPH_H
#include "VertexNode.h"





/*TODO:
1. Overloading AddEdge function?.
4. Print graph (No specific format given)

2 options to init graph:
	- Empty C'tor (Empty graph with no vertices) -> ReadGraph from keyboard.
	- C'tor that gets number of vertices (i.e MakeEmptyGraph()) -- Creates empty graph with n vertices
*/





class Graph
{
private:
	int m_numVertices;
	VertexNode** m_NeighborList;
	VertexNode* m_Head;
	VertexNode* m_Tail;
	
public:
	~Graph();
	/*
	* Creates empty graph with n vertices.
	* @param: number of vertices in the graph.
	*/
	void MakeEmptyGraph(int i_NumVertices);

	/*
	* Returns true if the given edge is exists in the graph. Else false.
	* @params: vertex v, vertex u for representing the edge.
	*/
	bool IsAdjacent(int v, int u);

	/*
	Returns a list of adjacent. nullptr in case there isn't one for the given vertex.
	@param: vertex u*/
	VertexNode* GetAdjList(int u);

	/*
	Adds a neighbor to a given vertex in the neighbor list
	*/
	void AddEdge(int u, int v);

	/*
	Remove an edge from the graph by removing vertex u from adjacent list of v
	*/
	void RemoveEdge(int u, int v);
	void ReadGraph();
	void PrintGraph();
	int IsEmpty();
	

	//TODO
	int AddEdge(int i, int j);
	Graph* InverseGraph(Graph* g);
	Graph* FindShortestPaths(int s, int t);
	Graph* BFS(Graph* g, int s);
	///
};

#endif // !__GRAPH_H