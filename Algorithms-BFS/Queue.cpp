#include "Queue.h"

Queue::Queue()
{
	m_Tail = m_Head = nullptr;
}

QNode* Queue::Dequeue()
{
	if (m_Head == nullptr)
	{
		return nullptr;
	}
	QNode* res = m_Head;
	m_Head = m_Head->next;

	if (m_Head == nullptr)
	{
		m_Tail = nullptr;
	}
	return res;
}

void Queue::Enqueue(Vertex* v)
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