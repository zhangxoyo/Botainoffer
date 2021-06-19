// offer23.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};


//快指针追上慢指针
ListNode* FindLoop(ListNode* pHead)
{
	if (pHead == nullptr)
	{
		return nullptr;
	}

	ListNode* pSlow = pHead->m_pNext;
	if (pSlow == nullptr)
	{
		return nullptr;
	}

	ListNode* pFast = pHead->m_pNext;
	if (pFast == nullptr)
	{
		return nullptr;
	}

	while (pFast != nullptr && pSlow != nullptr)
	{
		if (pFast == pSlow)
			return pFast;
		pFast = pFast->m_pNext;
		if (pFast == nullptr)
		{
			return nullptr;
		}
		pFast = pFast->m_pNext;
		pSlow = pSlow->m_pNext;

	}
	return nullptr;
}

ListNode* FindLoopEntry(ListNode* pHead)
{
	if (pHead == nullptr)
	{
		return nullptr;
	}

	ListNode* loopNode = FindLoop(pHead);
	if (loopNode == nullptr)
	{
		return nullptr;
	}
	int nCount = 1;
	ListNode* pTmp = loopNode->m_pNext;
	while (pTmp != loopNode && pTmp != nullptr)
	{
		pTmp = loopNode->m_pNext;
		nCount++;
	}

	ListNode* pFirst = pHead;
	while (pFirst != nullptr && nCount!= 0)
	{
		pFirst = pFirst->m_pNext;
		nCount--;
	}

	ListNode* pSecond = pHead;

	while (pFirst != pSecond)
	{
		pFirst = pFirst->m_pNext;
		pSecond = pSecond->m_pNext;
	}
}


int main()
{
    return 0;
}

