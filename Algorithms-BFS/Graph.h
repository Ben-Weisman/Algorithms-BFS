#ifndef __GRAPH_H
#define __GRAPH_H
#include "VertexNode.h"
#include "Queue.h"
#include "InputOutput.h"



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
	Graph() = default;
	Graph(const Graph& g);
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
	Remove an edge from the graph by removing vertex v from adjacent list of u
	*/
	void RemoveEdge(int u, int v);

	/*
	BFS algorithm.
	Param: source vertex s
	returns: d array which represents the shortest distance of each vertex v from source vertex s
	*/
	int* BFS(int s);
	
	void RemoveIrrelevantEdges(int* d, int s);

	void RemoveUnaccessibleVerticesAndItsEdges(int* d);
	void RemoveVetexEdges(int vertexId);
	void ReadGraph();

	int getNumberOfVertex();

	void PrintGraph();
	int IsEmpty();
	

	//TODO
	Graph* CreateTransposeGraph(Graph* g);
	Graph* FindShortestPaths(int s, int t);
	
	///
};

#endif // !__GRAPH_H