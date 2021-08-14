#ifndef __GRAPH_H
#define __GRAPH_H
#include "VertexNode.h"
#include "Queue.h"
class InputOutput; // forward declaration

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
	/// <summary>
	/// 
	/// </summary>
	/// <param name="i_d"></param>
	/// <param name="i_VertexNum"></param>
	/// <returns></returns>
	bool IsPathExists(const int* i_d, const int i_VertexNum);

public:
	Graph();
	~Graph();
	Graph(const Graph& g); // copy c'tor
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
	void AddEdge(const int u,const int v);

	/*
	Remove an edge from the graph by removing vertex v from adjacent list of u
	*/
	void RemoveEdge(int u, int v);

	/*
	BFS algorithm.
	Param: source vertex s
	returns: d array which represents the shortest distance of each vertex v from source vertex s
	*/
	int* BFS(int s, int* i_p);

	/*
	Removes edges that are not part of the shortest path from s to given vertex v.
	Param: d array that represents the shortest path from s to given v, and the source vertex (Created at BFS method).
	*/
	void RemoveLongerPathsFromGraph(int* d, int s);

	/*
	Removes all vertices that are not part of the shortest path from s to t. (that are not part of the connected component of the graph.
	Param: d array that represents the shortest path from s to given v, and the source vertex (Created at BFS method).*/
	void RemoveUnaccessibleVerticesAndItsEdges(int* d);


	void RemoveVertexAndItsEdges(int vertexId);

	/*
	Reads the graph from stdin using InputOutput class.*/
	void ReadGraph();


	// returns m_numVertices.
	int GetNumberOfVertices();

	bool IsEmpty();

	/*
	Returns the transpose of given g graph. 
	Param: Graph g
	*/
	Graph* CreateTransposeGraph(Graph* g);

	/*
	The algorithm implemented
	Param: source vertex s and destination vertex t
	*/
	Graph* FindShortestPaths(int s, int t);

	VertexNode** GetNeighborList();

};

#endif // !__GRAPH_H