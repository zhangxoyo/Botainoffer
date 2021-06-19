// offer35.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


struct ComplexListNode
{
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
};

void CreateCopyList(ComplexListNode* pNode)
{
	if (pNode == nullptr)
	{
		return;
	}

	while (pNode != nullptr)
	{
		ComplexListNode* pCloned = new ComplexListNode;
		pCloned->m_nValue = pNode->m_nValue;
		pCloned->m_pNext = pNode->m_pNext;
		pCloned->m_pSibling = nullptr;
		pNode->m_pNext = pCloned;
		pNode = pCloned->m_pNext;
	}
}

void SetClonedNodeSibling(ComplexListNode* pNode)
{
	if (pNode == nullptr)
	{
		return;
	}
	while (pNode != nullptr /*&& pNode->m_pNext != nullptr*/)
	{
		ComplexListNode* pCloned = pNode->m_pNext;
		ComplexListNode* pNodeSibling = pNode->m_pSibling;
		if (pNodeSibling != nullptr)
		{
			pCloned->m_pSibling = pNodeSibling->m_pNext;
		}
		
		pCloned = pCloned->m_pNext;
	}
	
}

ComplexListNode* SplitTwoList(ComplexListNode* pNode)
{
	if (pNode == nullptr)
	{
		return;
	}

	ComplexListNode* pClonedHead ;
	ComplexListNode* pClonedNode;
	if (pNode != nullptr)
	{
		pClonedHead = pClonedNode = pNode->m_pNext;
		pNode->m_pNext = pClonedHead->m_pNext;
		pNode = pNode->m_pNext;
	}

	while (pNode != nullptr)
	{
		pClonedNode->m_pNext = pNode->m_pNext;
		pClonedNode = pNode->m_pNext;
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}
	return pClonedHead;
}

int main()
{
    return 0;
}

