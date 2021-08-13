#include "Graph.h"


// TODO: write in readme that sectoin B could be done inside section A, but we followed the algorithm instructions as mentioned. 
// We also could create a new and EMPTY graph and just add the relevant Edges, but we instead copied the existing one and removed the irrelevant edges.

Graph::Graph(const Graph& g)
{
	Graph* res = new Graph();
	res->MakeEmptyGraph(g.m_numVertices);

	VertexNode* u = g.m_Head;
	VertexNode* v = nullptr;

	while (u != nullptr)
	{
		v = u->GetVertexNeighbors();
		while (v != nullptr)
		{
			res->AddEdge(u->GetVertexNum(), v->GetVertexNum());
			v->GetNext();
		}
		u->GetNext();
	}
}

Graph::~Graph()
{
	for (int i = 0; i < m_numVertices; i++)
	{
		VertexNode* currAdjNode = m_NeighborList[i]->GetVertexNeighbors();
		while (currAdjNode != nullptr)
		{
			VertexNode* tmpNodePtr = currAdjNode->GetNext();
			delete currAdjNode;
			currAdjNode = tmpNodePtr;
		}
	}
	delete[]m_NeighborList;
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
		VertexNode* currAdjNode = sourceVertex->GetVertexNeighbors();

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
	if (m_NeighborList[u - 1] == nullptr)
	{
		return nullptr;
	}
	return m_NeighborList[u - 1]->GetVertexNeighbors();
}



void Graph::RemoveEdge(int v, int u)
{
	VertexNode* sourceNode = m_NeighborList[v - 1];
	VertexNode* currAdjVertex = sourceNode->GetVertexNeighbors();
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
		res = 1;
	return res;
}

void Graph::AddEdge(int i, int j)
{
	if ((i >= 1 && i <= m_numVertices) && (j >= 1 && j <= m_numVertices))
	{
		VertexNode* sourceVertex = m_NeighborList[i - 1];
		VertexNode* newNode = new VertexNode(j);
		sourceVertex->GetVertexLastNeighbor()->SetNext(newNode);
		sourceVertex->SetVertexLastNeighbor(newNode);
	}

}

int* Graph::BFS(int s)
{

	int* d = new int[m_numVertices];
	Queue q;
	int u;

	// Init values of d array to -1;
	for (int i = 0; i < m_numVertices; i++)
	{
		d[i] = -1;
	}

	// Source is the first vertex to be visited.
	q.Enqueue(new VertexNode(s));

	// Distance from source to itself is 0.
	d[s - 1] = 0;


	while (!q.IsEmpty())
	{
		// u = prev vertex
		// i = u's neighbor (as type VertexNode)
		u = q.Dequeue()->vertexNode->GetVertexNum() - 1;
		for (VertexNode* i = m_NeighborList[u]->GetVertexNeighbors(); i != nullptr; i = i->GetNext()) // Iterate through all of u's neighbors.
		{
			int v = i->GetVertexNum() - 1; // u's neighbor integer value

			if (d[v] == -1) // check if d[v] isn't updated yet. 
			{
				d[v] = d[u] + 1;
				q.Enqueue(i);
			}
			else if (d[v] > d[u] + 1)
			{
				d[v] = d[u] + 1;
			}
		}
	}

	return d;

}

Graph* Graph::FindShortestPaths(int s, int t)
{
	int* d = Graph::BFS(s); // Section A
	Graph* gs = this; // TODO: check if correct copying
	if (d[t - 1] == -1)
	{
		return nullptr;
	}
	gs->RemoveIrrelevantEdges(d, s); // Section B
	gs->RemoveUnaccessibleVerticesAndItsEdges(d);

	Graph* gsTranspose = CreateTransposeGraph(gs); // Part C

	d = gsTranspose->BFS(t); // Part D
	if (d[s - 1] == -1)
	{
		return nullptr;
	}
	gsTranspose->RemoveUnaccessibleVerticesAndItsEdges(d);
	return gsTranspose->CreateTransposeGraph(gsTranspose); // Section E

}

void Graph::RemoveIrrelevantEdges(int* d, int s)
{
	VertexNode* currentVertex = m_NeighborList[s - 1];
	VertexNode* neighborOfCurrentVertex = nullptr;


	Queue q;
	int u;


	// Source is the first vertex to be visited.
	q.Enqueue(new VertexNode(s));

	while (!q.IsEmpty())
	{
		// u = prev vertex
		// i = u's neighbor (as type VertexNode)
		u = q.Dequeue()->vertexNode->GetVertexNum();
		for (VertexNode* i = m_NeighborList[u]->GetVertexNeighbors(); i != nullptr; i = i->GetNext()) // Iterate through all of u's neighbors.
		{
			int v = i->GetVertexNum(); // u's neighbor integer value

			if (d[u - 1] + 1 > d[v - 1])
			{
				RemoveEdge(u, v);
			}
		}
	}
}

void Graph::RemoveUnaccessibleVerticesAndItsEdges(int* d)
{
	//TODO: Implement RemoveAllEdges & RemoveVertex.
	for (int i = 0; i < m_numVertices; i++)
	{
		if (d[i] == -1) // Vertex is inaccessible 
		{
			RemoveVetexEdges(i + 1);
		}
	}
}
void Graph :: RemoveVetexEdges(int vertexId)
{
	VertexNode* neighbor = m_NeighborList[vertexId - 1]->GetVertexNeighbors();
	VertexNode* nextNeighbor;
	while (neighbor !=nullptr)
	{
		nextNeighbor = neighbor->GetNext();
		delete[] neighbor;
		neighbor = nextNeighbor;
	}
	// delete m_NeighborList[vertexId - 1]
//TODO: should re- organized the array or should we just print the vertex and the heighbors that not nullptr?
}
void Graph::ReadGraph()
{
	InpuOutput io;
	int numberOfEdges;
	int* arrayOfEdges = io.getEdges(numberOfEdges, m_numVertices);

	for (int i = 0; i < numberOfEdges * 2; i += 2)
	{
		this->AddEdge(i, i + 1);
	}
};

int Graph::getNumberOfVertex()
{
	return m_numVertices;
}