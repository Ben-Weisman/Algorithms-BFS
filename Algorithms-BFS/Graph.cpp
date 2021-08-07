#include "Graph.h"


Graph::~Graph()
{
	for (int i = 0; i < m_numVertices; i++)
	{
		VertexNode* currAdjNode = m_NeighborList[i]->GetSubListHeader();
		while (currAdjNode != nullptr)
		{
			VertexNode* tmpNodePtr = currAdjNode->GetNext();
			delete currAdjNode;
			currAdjNode = tmpNodePtr;
		}
	}
	delete []m_NeighborList;
}

void Graph::MakeEmptyGraph(int i_NumVertices)
{
	if (i_NumVertices > 0)
	{
		m_NeighborList = new VertexNode * [i_NumVertices];

		for (int i = 0; i < i_NumVertices; i++)
		{
			m_NeighborList[i] = nullptr;
		}
	}
}	



bool Graph::IsAdjacent(int v, int u)
{
	bool res = false;
	if ((v >= 1 && v <= m_numVertices) && (u >= 1 && u <= m_numVertices))
	{
		VertexNode* sourceVertex = m_NeighborList[v - 1];
		VertexNode* currAdjNode = sourceVertex->GetSubListHeader();

		while (currAdjNode != nullptr)
		{
			if (currAdjNode->GetVertexNum() == u)
			{
				res = true;
				break;
			}
		}
	}
	
	return res;
}

VertexNode* Graph::GetAdjList(int u)
{
	return m_NeighborList[u - 1]->GetSubListHeader();
}

void Graph::AddEdge(int v, int u)
{

		VertexNode* sourceVertex = m_NeighborList[v - 1];
		VertexNode* newNode = new VertexNode(u);
		sourceVertex->GetSubListTail()->SetNext(newNode);
		sourceVertex->SetSubListTail(newNode);

}

void Graph::RemoveEdge(int v, int u)
{
	VertexNode* sourceNode = m_NeighborList[v - 1];
	VertexNode* currAdjVertex = sourceNode->GetSubListHeader();
	VertexNode* prevNode = nullptr;

	while (currAdjVertex != nullptr)
	{
		if (currAdjVertex->GetVertexNum() == u)
		{
			if (prevNode != nullptr) 
			{
				prevNode->SetNext(currAdjVertex->GetNext());
			}
			else // first node was found
			{
				sourceNode->SetSubListHeader(currAdjVertex->GetNext());
			}
			delete currAdjVertex;
			break;
		}
		prevNode = currAdjVertex;
		currAdjVertex = currAdjVertex->GetNext();
		
	}

}

int Graph::IsEmpty()
{
	int res = 0;
	if (m_numVertices == 0)
		res =  1;
	return res;
}

int Graph::AddEdge(int i, int j)
{
	int res = 0;
	if ((i >= 1 && i <= m_numVertices) && (j >= 1 && j <= m_numVertices))
	{
		VertexNode* sourceVertex = m_NeighborList[i - 1];
		VertexNode* newNode = new VertexNode(j);
		sourceVertex->GetSubListTail()->SetNext(newNode);
		sourceVertex->SetSubListTail(newNode);
		res = 1;
	}
	return res;
	
}