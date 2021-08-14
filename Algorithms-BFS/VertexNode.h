#ifndef __VERTEXNODE_H
#define __VERTEXNODE_H

class VertexNode
{
private:
	const int m_VertexNum;
	VertexNode* m_Next;
	VertexNode* m_SubListHead;
	VertexNode* m_SubListTail;
public:

	VertexNode(int i_VertexNum);
	const int GetVertexNum();
	VertexNode* GetNext();
	VertexNode* GetVertexNeighbors();
	VertexNode* GetVertexLastNeighbor();
	void SetNext(VertexNode* i_Next);
	void SetSubListHeader(VertexNode* i_Head);
	void SetVertexLastNeighbor(VertexNode* i_Tail);
};
#endif // !__VERTEXNODE_H