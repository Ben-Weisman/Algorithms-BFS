#ifndef __QUEUE_H
#define __QUEUE_H
#include "Vertex.h"

// Queue data node contains a reference to a Vertex.
struct QNode {
	Vertex* data;
	QNode* next;
	QNode(Vertex* v)
	{
		data = v;
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
	void Enqueue(Vertex* v);
	QNode* Dequeue();
	bool IsEmpty();
	QNode* Peek();
};

#endif // !__QUEUE_H