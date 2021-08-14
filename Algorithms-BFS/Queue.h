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
	/// <summary>
	/// constractor of Q
	/// </summary>
	Queue();

	/// <summary>
	/// Inserting Qnode inside the queu
	/// </summary>
	/// <param name="v">The vertex node that the Qnode should contain</param>
	void Enqueue(VertexNode* v);

	/// <summary>
	/// Getting out fron the queue the next item in the queue.
	/// </summary>
	/// <returns>A vertex node that the qnode contain.</returns>
	VertexNode* Dequeue();

	/// <summary>
	/// Checking if the Q is empty
	/// </summary>
	/// <returns></returns>
	bool IsEmpty();

	QNode* Peek();
};

#endif // !__QUEUE_H