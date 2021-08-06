#ifndef __NEIGHBORLIST_H
#define __NEIGHBORLIST_H
#include "Vertex.h"

struct VertexNode {
	Vertex* data;
	VertexNode* next;
	VertexNode* subList;

	VertexNode(Vertex* v)
	{
		data = v;
		next = subList = nullptr;
	}

};
class NeighborList 
{
private:
	VertexNode* m_Head;
	VertexNode* m_Tail;

public:
	NeighborList(int numVertices);
};

#endif // !__NEIGHBORLIST_H