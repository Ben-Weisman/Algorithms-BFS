#ifndef __INPUTOUTPUT_H
#define __INPUTOUTPUT_H

#include "Graph.h"
#include <iomanip>
#include <iostream>
using namespace std;


#define MIN_RANGE_OF_VERTEX 1
#define MIN_AMOUNT_OF_VERTEX 2

/// <summary>
/// This class is static, and used for comunication between the user and the system.
/// All the input and output of this pprogram to the console pass throw here.
/// </summary>
static class InpuOutput
{
public:
	/// <summary>
	/// getting the max number of vertex.
	/// </summary>
	/// <returns>int,max number of vertex.</returns>
	static int getCountOfVertexFromUser();

	/// <summary>
	/// Getting from user the head of the path.
	/// </summary>
	/// <param name="i_MaxValueOfVertex"> The max number of vertex</param>
	/// <returns>int the first vertex of the path</returns>
	static int getStartVertex(int i_MaxValueOfVertex);

	/// <summary>
	/// Getting from user the tail of the path.
	/// </summary>
	/// <param name="i_MaxValueOfVertex"> The max number of vertex</param>
	/// <returns>int the last vertex of the path</returns>
	static int getTargetVertex(int i_MaxValueOfVertex);

	/// <summary>
	/// Reading int values, and every two values are consider as edge, and the edge being addition to the graph.
	/// </summary>
	/// <param name="g">The graph that the user wants to add the edge.</param>
	static void addingEdgesFromUser(Graph& g);

	/// <summary>
	/// printing the graph in the structer: "[source vertex] [destination vertex] [\n]"
	/// </summary>
	/// <param name="i_g">The graph we want to pring</param>
	static void printGraph(Graph& i_g);

	/// <summary>
	/// After we found there is no path between to vertexes, we priniting a message and exit the program.
	/// </summary>
	static void printNoPathErrorAndExit();

	/// <summary>
	/// Printing the time that the run time of the algorithm functio (FindShortestPaths) taken.
	/// </summary>
	/// <param name="i_timeTaken"></param>
	static void PrintRunTimeValue(double i_timeTaken);

	/// <summary>
	/// Printing message if the start and the end of the path are the same vertex.
	/// </summary>
	static void printIdenticalStartAndEndVertexes();

private:
	/// <summary>
	/// Printing and error while there is an input error, and exiting the program
	/// </summary>
	static void PrintErrorInputMessageAndExit();

	/// <summary>
	/// Checing if vertex that given to this function (most of the time directly from the user),
	///  is in the right range of the graph vertex numbers.
	/// </summary>
	/// <param name="i_VertexId">The vertex that should be checked</param>
	/// <param name="i_MaxIndex">The max number of vertex</param>
	/// <returns>bool, true if the vertex in range</returns>
	static bool isVertexInRange(int i_VertexId, int i_MaxIndex);
};
#endif // !__INPUTOUTPUT_H
