#ifndef __INPUTOUTPUT_H
#define __INPUTOUTPUT_H

#include "Graph.h"

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

private:
	static void insertNumberToArray(int& io_PhyzSize, int& io_LogicSize, int i_number, int* io_Array);
	static bool isWhitespace(char i_ch);
	static void PrintErrorInputMessageAndExit();
	static bool isVertexInRange(int i_VertexId, int i_MaxIndex);
};
#endif // !__INPUTOUTPUT_H
