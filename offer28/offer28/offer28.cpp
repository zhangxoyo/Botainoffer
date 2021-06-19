// offer28.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

struct ListNode
{
	int m_nValue;
	ListNode* m_pLeft;
	ListNode* m_pRight;
};

bool IsMirrorBinaryTree(ListNode* pNode1, ListNode* pNode2)
{
	if (pNode1 == nullptr && pNode2 == nullptr)
	{
		return true;
	}

	if (pNode1 == nullptr || pNode2 == nullptr)
	{
		return false;
	}

	if (pNode1->m_nValue != pNode2->m_nValue)
	{
		return false;
	}

	return IsMirrorBinaryTree(pNode1->m_pLeft, pNode2->m_pRight) \
		&&IsMirrorBinaryTree(pNode1->m_pRight, pNode2->m_pLeft);
}

bool IsMirrorBinaryTree(ListNode* pNode)
{
	return IsMirrorBinaryTree(pNode, pNode);
}

int main()
{
    return 0;
}

