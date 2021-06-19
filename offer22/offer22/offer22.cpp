// offer22.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<memory>

using std::endl;
using std::cout;
using std::cin;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};


ListNode* FindLastKthNode(ListNode* pHead, int k)
{
	if (pHead == nullptr)
	{
		return nullptr;
	}

	ListNode* pBegin = pHead;
	int nIndex = 1;
	if (k == 0)
	{
		return pHead;
	}
	while (pBegin->m_pNext != nullptr)
	{
		if (nIndex == k)
			break;
		pBegin = pBegin->m_pNext;
		nIndex++;
		if (nIndex == k)
			break;
	}
	if (nIndex != k)
	{
		return nullptr;
	}
	while (pBegin != nullptr)
	{
		pBegin = pBegin->m_pNext;
		pHead = pHead->m_pNext;
	}
	return pHead
	
int main()
{
    return 0;
}

