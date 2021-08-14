#include "InputOutput.h"



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
	cin >> sourceVertex;
	cin.ignore();
	while (!cin.fail())
	{

		cin >> destinationVertex;


		if (!isVertexInRange(sourceVertex, maxVertexNum) || !isVertexInRange(destinationVertex, maxVertexNum) || cin.fail())
		{
			PrintErrorInputMessageAndExit();
		}
		else
		{
			g.AddEdge(sourceVertex, destinationVertex);
		}
		cin >> sourceVertex;

	}
}


void InpuOutput::printGraph(Graph& i_g)
{

	VertexNode* currentVertexNeghiborList;
	cout << "The edges are:\n";
	for (int i = 1; i <= i_g.GetNumberOfVertices(); i++)
	{
		if (i_g.GetNeighborList()[i - 1] != nullptr)
		{
			currentVertexNeghiborList = i_g.GetAdjList(i);
			while (currentVertexNeghiborList != nullptr)
			{
				int n = currentVertexNeghiborList->GetVertexNum();
				cout << i << " " << n << " "<<'\n';
				currentVertexNeghiborList = currentVertexNeghiborList->GetNext();
			}
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


void InpuOutput::PrintRunTimeValue(double i_timeTaken)
{

	i_timeTaken *= 1e-9;
	cout << "Time taken by function 'FindShortestPaths' is : ";
	cout << fixed;
	cout << setprecision(9);
	cout<< i_timeTaken << setprecision(9) << " sec" << endl;
}

void InpuOutput::printIdenticalStartAndEndVertexes()
{
	cout << "'s' and 't' vertexes are the same vertex the shortest path includes 0 edges.";
}
