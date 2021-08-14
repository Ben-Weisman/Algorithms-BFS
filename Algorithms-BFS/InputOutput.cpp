#include "InputOutput.h"
#include <iostream>
using namespace std;



int InpuOutput::getCountOfVertexFromUser()
{
	int maxVertexIndex;
	cout << "Please enter the amount of vertexes: ";
	cin >> maxVertexIndex;
	if (maxVertexIndex < MIN_AMOUNT_OF_VERTEX)
	{
		PrintErrorMessageAndExit();
	}
	return maxVertexIndex;
}


void InpuOutput::PrintErrorMessageAndExit()
{
	cout << "Wrong Input";
	exit(1);
}

int InpuOutput::getStartVertex(int i_MaxValueOfVertex)
{
	int sVertex;
	cout << "Please enter the vertex you want to start with ('s' vertex):";
	cin >> sVertex;
	if (!isVertexInRange(sVertex, i_MaxValueOfVertex))
	{
		PrintErrorMessageAndExit();
	}
	return sVertex;
}

int InpuOutput::getTargetVertex(int i_MaxValueOfVertex)
{
	int tVertex;
	cout << "Please enter the target vertex ('t' vertex):";
	cin >> tVertex;
	if (!isVertexInRange(tVertex, i_MaxValueOfVertex))
	{
		PrintErrorMessageAndExit();
	}
	return tVertex;

}

int* InpuOutput::getEdges(int& o_NumberOfEdegs, int i_maxVertexId)
{

	bool result = true;
	bool valid = true;
	int currentNumber = 0;
	int numbersOfVertexEntered = 0;
	int logSize = 0;
	int index;
	char ch = 1;
	int logicSize = 0;
	int phyzSize = MIN_AMOUNT_OF_VERTEX;
	int* arr = new int[phyzSize];

	cout << "Please start to eneter the edges: ";

	while (ch != EOF)
	{
		ch = getchar();
		while (!isWhitespace(ch) && ch != EOF)
		{
			currentNumber = 10 * currentNumber + ch - '0';
			ch = getchar();
		}

		if (!isVertexInRange(currentNumber, i_maxVertexId))
		{
			PrintErrorMessageAndExit();
		}

		insertNumberToArray(phyzSize, logicSize, currentNumber, arr);

	}

	if (logicSize % 2 != 0)
	{
		PrintErrorMessageAndExit();
	}
	 
	o_NumberOfEdegs = logicSize / 2;

	return arr;

}
void InpuOutput::printGraph(Graph& i_g)
{
	VertexNode* currentVertexNeghiborList;
	for (int i = 1; i <= i_g.GetNumberOfVertices(); i++)
	{
		currentVertexNeghiborList = i_g.GetAdjList(i);
		while (currentVertexNeghiborList != nullptr)
		{
			cout << "(" + i + ',' + currentVertexNeghiborList->GetVertexNum() + '), ';
			currentVertexNeghiborList = currentVertexNeghiborList->GetNext();
		}

	}
}

void InpuOutput::printNoPathErrorAndExit()
{
	cout << "There is no existing path between s and t that you choose.";
	exit(2);
}

bool InpuOutput::isVertexInRange(int i_VertexId, int i_MaxIndex)
{
	if (i_VertexId >= MIN_RANGE_OF_VERTEX && i_VertexId <= i_MaxIndex)
	{
		return true;
	}
	return false;
}

void InpuOutput::insertNumberToArray(int& io_PhyzSize, int& io_LogicSize, int i_number, int* io_Array)
{
	int* newArr = nullptr;

	if (io_PhyzSize == io_LogicSize)
	{
		io_PhyzSize *= 2;
		newArr = new int[io_PhyzSize];
		memcpy(newArr, io_Array, sizeof(int) * io_LogicSize);
		delete[]io_Array;
		io_Array = newArr;
	}
	io_Array[io_LogicSize++];
}


bool InpuOutput::isWhitespace(char ch)
{
	return ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r' || ch == '\v' || ch == '\f';
}
