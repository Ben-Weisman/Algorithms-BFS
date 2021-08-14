#include "Graph.h"
#include "InputOutput.h"


Graph::Graph()
{
	m_Head = m_Tail = nullptr;
	m_numVertices = 0;
	m_NeighborList = nullptr;
};


Graph::Graph(const Graph& g)
{

	this->MakeEmptyGraph(g.m_numVertices);
	this->m_numVertices = g.m_numVertices;
	
	VertexNode* u;
	VertexNode* v = nullptr;

	for (int i = 0; i < g.m_numVertices; i++)
	{
		u = g.m_NeighborList[i];
		if (u != nullptr)
		{
			v = u->GetVertexNeighbors();
			while (v != nullptr)
			{
				this->AddEdge(u->GetVertexNum(), v->GetVertexNum());
				v = v->GetNext();
			}
			
		}
	}
}

Graph::~Graph()
{
	for (int i = 0; i < m_numVertices; i++)
	{
		if (m_NeighborList[i] != nullptr)
		{
			VertexNode* currAdjNode = m_NeighborList[i]->GetVertexNeighbors();
			while (currAdjNode != nullptr)
			{
				VertexNode* tmpNodePtr = currAdjNode->GetNext();
				delete currAdjNode;
				currAdjNode = tmpNodePtr;
			}
		}
	}
	delete[]m_NeighborList;
}

void Graph::MakeEmptyGraph(int i_NumVertices)
{
	m_numVertices = i_NumVertices;
	if (i_NumVertices > 0)
	{
		m_NeighborList = new VertexNode * [i_NumVertices];

		for (int i = 0; i < i_NumVertices; i++)
		{
			m_NeighborList[i] = new VertexNode(i+1);
		}
	}
	
}

bool Graph::IsAdjacent(int v, int u)
{
	bool res = false;
	if ((v >= 1 && v <= m_numVertices) && (u >= 1 && u <= m_numVertices))
	{
		VertexNode* sourceVertex = m_NeighborList[v - 1];

		if (sourceVertex != nullptr)
		{
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
	}

	return res;
}

VertexNode* Graph::GetAdjList(int u)
{
	VertexNode* res = nullptr;
	if (m_NeighborList[u - 1] != nullptr)
	{
		res = m_NeighborList[u - 1]->GetVertexNeighbors();
	}
	return res;
}



void Graph::RemoveEdge(int v, int u)
{
	VertexNode* sourceNode = m_NeighborList[v - 1];

	if (sourceNode != nullptr)
	{
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
}

bool Graph::IsEmpty()
{
	bool res = false;
	if (m_numVertices == 0)
		res = true;
	return res;
}

void Graph::AddEdge(const int i,const int j)
{
	if ((i >= 1 && i <= m_numVertices) && (j >= 1 && j <= m_numVertices))
	{
		VertexNode* sourceVertex = m_NeighborList[i - 1];

		if (sourceVertex != nullptr)
		{
			VertexNode* newNode = new VertexNode(j);
			if (sourceVertex->GetVertexNeighbors() == nullptr) // neighbors list is empty
			{
				sourceVertex->SetSubListHeader(newNode);
				sourceVertex->SetVertexLastNeighbor(newNode);
			}
			else 
			{
				sourceVertex->GetVertexLastNeighbor()->SetNext(newNode);
				sourceVertex->SetVertexLastNeighbor(newNode);
			}

		}
	}
}

int* Graph::BFS(int s, int* i_p)
{

	int* d = new int[m_numVertices];
	Queue q;
	int u;

	// Init values of d array to -1;
	for (int i = 0; i < m_numVertices; i++)
	{
		d[i] = -1;
		i_p[i] = -1;
	}

	// Source is the first vertex to be visited.
	q.Enqueue(new VertexNode(s));

	// Distance from source to itself is 0.
	d[s - 1] = 0;


	while (!q.IsEmpty())
	{
		// u = prev vertex
		u = q.Dequeue()->GetVertexNum() - 1;

		VertexNode* currAdj = m_NeighborList[u]->GetVertexNeighbors();

		while (currAdj != nullptr)
		{
			int v = currAdj->GetVertexNum() - 1; // u's neighbor integer value

			if (d[v] == -1) // check if d[v] isn't updated yet. 
			{
				d[v] = d[u] + 1;
				i_p[v] = u + 1;
				q.Enqueue(currAdj);
			}
			else if (d[v] > d[u] + 1)
			{
				d[v] = d[u] + 1;
			}
			currAdj = currAdj->GetNext();
		}
	}

	return d;

}

Graph* Graph::FindShortestPaths(int s, int t)
{
	int* p = new int [m_numVertices];
	int* d = Graph::BFS(s, p); // Section A
	Graph* gs = new Graph(*this); 
	if (!IsPathExists(d, t))
	{
		return nullptr;
	}
	gs->RemoveLongerPathsFromGraph(d, s); // Section B
	gs->RemoveUnaccessibleVerticesAndItsEdges(d);

	Graph* gsTranspose = CreateTransposeGraph(gs); // Part C

	d = gsTranspose->BFS(t,p); // Part D
	if (!IsPathExists(d, s))
	{
		return nullptr;
	}
	gsTranspose->RemoveUnaccessibleVerticesAndItsEdges(d);
	delete[] d;
	delete gs;
	Graph* hRes = gsTranspose->CreateTransposeGraph(gsTranspose); // Section E
	delete gsTranspose;
	delete[] p;
	return hRes;
	
}

void Graph::RemoveLongerPathsFromGraph(int* d, int s)
{
	for (int i = 0; i < this->m_numVertices; i++)
	{
		VertexNode* currAdj = this->m_NeighborList[i]->GetVertexNeighbors();

		while (currAdj != nullptr)
		{
			int v = currAdj->GetVertexNum();
			if (d[i] + 1 > d[v - 1])
			{
				VertexNode* nextNodePtr = currAdj->GetNext();
				RemoveEdge(i+1, v);
				currAdj = nextNodePtr;
			}
			else
			{
				currAdj = currAdj->GetNext();
			}
			
		}
	}
}

void Graph::RemoveUnaccessibleVerticesAndItsEdges(int* d)
{
	
	for (int i = 0; i < m_numVertices; i++)
	{
		if (d[i] == -1) // Vertex is inaccessible 
		{
			RemoveVertexAndItsEdges(i + 1);
		}
	}
}
void Graph::RemoveVertexAndItsEdges(int i_vertexNum)
{
	if (m_NeighborList[i_vertexNum - 1] != nullptr)
	{
		VertexNode* neighbor = m_NeighborList[i_vertexNum - 1]->GetVertexNeighbors();
		VertexNode* nextNeighbor;
		while (neighbor != nullptr)
		{
			nextNeighbor = neighbor->GetNext();
			delete neighbor;
			neighbor = nextNeighbor;
		}
		VertexNode* tmp = m_NeighborList[i_vertexNum - 1];
		delete tmp;
		m_NeighborList[i_vertexNum - 1] = nullptr;
	}
}
void Graph::ReadGraph()
{
	InpuOutput io;
	io.addingEdgesFromUser(*this);
}

int Graph::GetNumberOfVertices()
{
	return m_numVertices;
}

Graph* Graph::CreateTransposeGraph(Graph* g)
{
	Graph* gt = new Graph();
	VertexNode* iNeighbor;
	gt->MakeEmptyGraph(g->GetNumberOfVertices());

	for (int i = 0; i < g->GetNumberOfVertices(); i++)
	{
		if (g->GetAdjList(i + 1) != nullptr)
		{
			iNeighbor = g->GetAdjList(i + 1);
			while (iNeighbor != nullptr)
			{
				gt->AddEdge(iNeighbor->GetVertexNum(), i + 1);
				iNeighbor = iNeighbor->GetNext();
			}
		}
	}
	return gt;

};

bool Graph::IsPathExists(const int* d,const int i_VertexNum)
{
	return d[i_VertexNum - 1] != -1;
}

VertexNode** Graph::GetNeighborList()
{
	return m_NeighborList;
}