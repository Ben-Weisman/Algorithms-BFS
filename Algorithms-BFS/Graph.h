#ifndef __GRAPH_H
#define __GRAPH_H
#include "VertexNode.h"





/*TODO:
1. Overload AddEdge function.
2. Create c'tor (should get an array of int or string?
3. ReadGraph - how should we read it? From a file or a keyboard? what's the difference from the c'tor?
4. Print graph
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
	int AddEdge(int i, int j);
	Graph* InverseGraph(Graph* g);
	Graph* FindShortestPaths(int s, int t);
	
};

#endif // !__GRAPH_H