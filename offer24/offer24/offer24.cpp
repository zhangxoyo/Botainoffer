// offer24.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>


struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};


ListNode* ReverseList(ListNode* pHead)
{
	if (pHead == nullptr)
	{
		return nullptr;
	}
	ListNode* pre = pHead;
	pre->m_pNext = nullptr;
	ListNode* pNext = pHead->m_pNext;

	while (pNext!= nullptr)
	{
		ListNode* pNextByNext = pNext->m_pNext;
		pNext->m_pNext = pre;
		pre = pNext;
		pNext = pNextByNext;
	}
	return pre;
}

int main()
{
    return 0;
}

