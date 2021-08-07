#ifndef __VERTEXNODE_H
#define __VERTEXNODE_H

class VertexNode
{
private:
	int m_VertexNums;
	VertexNode* m_Next;
	VertexNode* m_SubListHead;
	VertexNode* m_SubListTail;
public:

	VertexNode(int i_VertexNum);
	int GetVertexNum();
	VertexNode* GetNext();
	VertexNode* GetSubListHeader();
	VertexNode* GetSubListTail();
	void SetNext(VertexNode* i_Next);
	void SetSubListHeader(VertexNode* i_Head);
	void SetSubListTail(VertexNode* i_Tail);

};
#endif // !__VERTEXNODE_H