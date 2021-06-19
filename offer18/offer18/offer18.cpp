// offer18.cpp : 定义控制台应用程序的入口点。
//删除链表的节点，时间复杂度O(1)
//删除排序链表中的重复元素

#include "stdafx.h"

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

void DeleteNode(ListNode* Head, ListNode* Node)
{
	if (Head == nullptr || Node == nullptr)
	{
		return;
	}
	ListNode* Next = Node->m_pNext;

	if (Head == Node)
	{
		delete Head;
		Head = nullptr;
	}
	if (Next == nullptr)
	{
		delete Node;
		Node = nullptr;
	}
	Node->m_nValue = Next->m_nValue;

	Node->m_pNext = Next->m_pNext;
	delete Next;
}

void DeleteDuplicationNode(ListNode* pHead)
{
	if (pHead == nullptr)
	{
		return;
	}
	if (pHead->m_pNext == nullptr)
	{
		return;
	}
	ListNode* pNode = pHead->m_pNext;
	ListNode* pPreNode = pHead;
	while (pNode != nullptr)
	{
		while(pNode != nullptr && pNode->m_nValue == pPreNode->m_nValue)
		{
			ListNode* pTmp = pNode;
			pNode = pNode->m_pNext;
			delete pTmp;
		}
		pPreNode->m_pNext = pNode;
		pPreNode = pNode;
		pNode = pNode->m_pNext;

	}
}

int main()
{
    return 0;
}

