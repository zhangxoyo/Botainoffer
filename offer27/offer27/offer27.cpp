// offer27.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>

struct ListNode
{
	int m_nValue;
	ListNode* m_pLeft;
	ListNode* m_pRight;
};

void MirrorRecursively(ListNode* pNode)
{
	if (pNode == nullptr)
	{
		return;
	}

	if (pNode->m_pLeft == nullptr && pNode->m_pRight == nullptr)
	{
		return;
	}

	ListNode* pTmp = pNode->m_pLeft;
	pNode->m_pLeft = pNode->m_pRight;
	pNode->m_pRight = pTmp;

	if (pNode->m_pLeft)
	{
		MirrorRecursively(pNode->m_pLeft);
	}

	if (pNode->m_pRight)
	{
		MirrorRecursively(pNode->m_pRight);
	}
}

int main()
{
    return 0;
}

