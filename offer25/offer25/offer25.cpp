// offer25.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

struct ListNode
{
	int m_pValue;
	ListNode* m_pNext;
};

ListNode* MergeTwoList(ListNode* pFirst, ListNode* pSecond)
{
	if (pFirst == nullptr)
	{
		return pSecond;
	}
	else if (pSecond == nullptr)
	{
		return pFirst;
	}

	ListNode* pMergeNode = nullptr;
	if (pFirst->m_pValue < pSecond->m_pValue)
	{
		pMergeNode = pFirst;
		pMergeNode->m_pNext = MergeTwoList(pFirst->m_pNext, pSecond);
	}
	else
	{
		pMergeNode = pSecond; 
		pMergeNode->m_pNext = MergeTwoList(pFirst, pSecond->m_pNext);
	}
	return pMergeNode;
}

int main()
{
    return 0;
}

