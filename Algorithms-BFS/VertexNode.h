#ifndef __VERTEXNODE_H
#define __VERTEXNODE_H


// Class Description:
// Each vertex in the graph is implemented using VertexNode class, which constains a constant vertex value (1-n)
// And a pointer to its adjacency list (if there is one).

class VertexNode
{
private:
	const int m_VertexNum;
	VertexNode* m_Next;
	VertexNode* m_SubListHead;
	VertexNode* m_SubListTail;
public:

	/// <summary>
	/// Constractor of vertex node.
	/// </summary>
	/// <param name="i_VertexNum">getting an number of the vertex,</param>
	VertexNode(int i_VertexNum);

	/// <summary>
	/// getting the num of the vertex.
	/// </summary>
	/// <returns>The number of the vertex,</returns>
	const int GetVertexNum();

	/// <summary>
	/// get the next vertex in the list.
	/// </summary>
	/// <returns>The next vertex after 'this' vertex in the list</returns>
	VertexNode* GetNext();

	/// <summary>
	/// getting pointer to the head list of "this" vertex neighbors. 
	/// </summary>
	/// <returns>Pointer to the head of the meighbor list of "this" vertex</returns>
	VertexNode* GetVertexNeighbors();

	/// <summary>
	/// Getting the last neighbor in the list according to the order the edges added.
	/// </summary>
	/// <returns>Pointer to the last nieghboe of "this" vertex</returns>
	VertexNode* GetVertexLastNeighbor();

	/// <summary>
	/// This function allow us to enter the list new vertex node.
	/// </summary>
	/// <param name="i_Next">a pointer to a vertex we want to add.</param>
	void SetNext(VertexNode* i_Next);

	/// <summary>
	/// Setter for the head of the neihnor list,
	/// </summary>
	/// <param name="i_Head">A pointer to the vertex node that should be added.</param>
	void SetSubListHeader(VertexNode* i_Head);

	/// <summary>
	/// Setter for the tail of the neighbor list,
	/// </summary>
	/// <param name="i_Tail">The pointer to the vertex node that should be added/</param>
	void SetVertexLastNeighbor(VertexNode* i_Tail);
};
#endif // !__VERTEXNODE_H