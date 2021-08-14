#ifndef __GRAPH_H
#define __GRAPH_H
#include "VertexNode.h"
#include "Queue.h"
class InputOutput; // forward declaration

// Class Description:
// This class represents a directed graph. 
// The Neibhbors list is implemented using VertexNode object.


class Graph
{
private:
	int m_numVertices;
	VertexNode** m_NeighborList;
	VertexNode* m_Head;
	VertexNode* m_Tail;


	/// <param name="i_d"></param>
	/// <param name="i_VertexNum"></param>
	/// <returns>bool if there is path to a specific vertex</returns>
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
	void AddEdge(const int u, const int v);

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

	/// <summary>
	/// removing the given edges and his nighbors from the neighbor list.
	/// </summary>
	/// <param name="vertexId"> The vertext the should be removed</param>
	void RemoveVertexAndItsEdges(int vertexId);

	/*
	Reads the graph from stdin using InputOutput class.*/
	void ReadGraph();


	// returns m_numVertices.
	int GetNumberOfVertices();

	/// <summary>
	/// Checking if this graph is empty;
	/// </summary>
	/// <returns></returns>
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


	/// <returns>Array of vertexes in the graph.</returns>
	VertexNode** GetNeighborList();

};

#endif // !__GRAPH_H