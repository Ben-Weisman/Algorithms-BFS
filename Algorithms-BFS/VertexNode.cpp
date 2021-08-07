#include "VertexNode.h"

VertexNode::VertexNode(int i_VertexNum)
{
	m_VertexNums = i_VertexNum;
	m_Next = m_SubListHead = m_SubListTail = nullptr;
}

int VertexNode::GetVertexNum()
{
	return m_VertexNums;
}

VertexNode* VertexNode::GetNext()
{
	return m_Next;
}

VertexNode* VertexNode::GetSubListHeader()
{
	return m_SubListHead;
}

VertexNode* VertexNode::GetSubListTail()
{
	return m_SubListTail;
}

void VertexNode::SetNext(VertexNode* i_Next)
{
	m_Next = i_Next;
}

void VertexNode::SetSubListHeader(VertexNode* i_Head)
{
	m_SubListHead = i_Head;
}
void VertexNode::SetSubListTail(VertexNode* i_Tail)
{
	m_SubListTail = i_Tail;
}