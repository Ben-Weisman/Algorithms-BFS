#ifndef __INPUTOUTPUT_H
#define __INPUTOUTPUT_H

#include "Graph.h"
#include <iomanip>
#include <iostream>
using namespace std;


#define MIN_RANGE_OF_VERTEX 1
#define MIN_AMOUNT_OF_VERTEX 2

static class InpuOutput
{
public:

	static int getCountOfVertexFromUser();
	static int getStartVertex(int i_MaxValueOfVertex);
	static int getTargetVertex(int i_MaxValueOfVertex);
	static void addingEdgesFromUser(Graph& g);
	static void printGraph(Graph& i_g);
	static void printNoPathErrorAndExit();
	static void NotInRamgeEror(int i_VertexId);
	static void PrintRunTimeValue(double i_timeTaken);
	static void printIdenticalStartAndEndVertexes();

private:
	static void PrintErrorInputMessageAndExit();
	static bool isVertexInRange(int i_VertexId, int i_MaxIndex);
};
#endif // !__INPUTOUTPUT_H
