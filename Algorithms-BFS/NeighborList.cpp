#include "NeighborList.h"

NeighborList::NeighborList(int numVertics)
{
	Vertex* newVertex = new Vertex(i);
	VertexNode* newNode = new VertexNode(newVertex);
	m_Tail = m_Head = newNode;

	for (int i = 1; i < numVertics; i++)
	{
		Vertex* newVertex = new Vertex(i);
		VertexNode* newNode = new VertexNode(newVertex);
		m_Tail->next = newNode;
		m_Tail = newNode;
	}
}