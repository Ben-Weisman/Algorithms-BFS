#ifndef __QUEUE_H
#define __QUEUE_H
#include "Graph.h"
#include "VertexNode.h"

// Class Description:
// Queue data node contains a reference to a VertexNode object instance.
struct QNode {

	VertexNode* vertexNode;
	QNode* next;

	QNode(VertexNode* v)
	{
		vertexNode = v;
		next = nullptr;
	}
};

class Queue
{
private:
	QNode* m_Tail;
	QNode* m_Head;


public:
	Queue();
	void Enqueue(VertexNode* v);
	VertexNode* Dequeue();
	bool IsEmpty();
	QNode* Peek();
};

#endif // !__QUEUE_H