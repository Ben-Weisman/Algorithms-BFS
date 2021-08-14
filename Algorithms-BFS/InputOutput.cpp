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
		PrintErrorInputMessageAndExit();
	}
	return maxVertexIndex;
}


void InpuOutput::PrintErrorInputMessageAndExit()
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
		PrintErrorInputMessageAndExit();
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
		PrintErrorInputMessageAndExit();
	}
	return tVertex;
}

void InpuOutput::addingEdgesFromUser(Graph& g)
{

	int maxVertexNum = g.GetNumberOfVertices();
	int sourceVertex = 0;
	int destinationVertex = 0;

	cout << "Please start to eneter the edges: ";

	while (!cin.fail())
	{
		cin >> sourceVertex;
		if (cin.fail())
		{
			break;
		}
		cin >> destinationVertex;
	

		if (cin.fail()|| !isVertexInRange(sourceVertex, maxVertexNum) || !isVertexInRange(destinationVertex, maxVertexNum))
		{
			PrintErrorInputMessageAndExit();
		}
		else
		{
			g.AddEdge(sourceVertex, destinationVertex);
		}
	}
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

void InpuOutput::NotInRamgeEror(int i_VertexId)
{
	cout << "Not In range\n" << i_VertexId << "\n";

}

