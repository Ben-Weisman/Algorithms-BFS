#include "Queue.h"

Queue::Queue()
{
	m_Tail = m_Head = nullptr;
}

VertexNode* Queue::Dequeue()
{
	if (m_Head == nullptr)
	{
		return nullptr;
	}
	QNode* toDequeue = m_Head;
	VertexNode* res = toDequeue->vertexNode;
	
	m_Head = m_Head->next;

	if (m_Head == nullptr)
	{
		m_Tail = nullptr;
	}

	toDequeue->vertexNode = nullptr;
	delete toDequeue;

	return res;
}

void Queue::Enqueue(VertexNode* v)
{
	QNode* node = new QNode(v);
	if (m_Head == nullptr) // Empty list
	{
		m_Head = m_Tail = node;
	}
	else
	{
		m_Tail->next = node;
		m_Tail = node;
	}
}

bool Queue::IsEmpty()
{
	return m_Head == nullptr;
}

QNode* Queue::Peek()
{
	return m_Head;
}