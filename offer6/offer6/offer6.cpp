// offer6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<memory>
#include<string>
#include<stack>
using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* pNext;
};

int ReversePrintList(ListNode* pHead)
{
	std::stack<ListNode*> stck;

	while (pHead != nullptr)
	{
		stck.push(pHead);
		pHead = pHead->pNext;
	}

	while (stck.size() != 0)
	{
		ListNode* node = stck.top();
		cout << node->m_nValue << " ";
		stck.pop();
	}
	return 0;
}

void RecursePrintList(ListNode* head)
{
	if (head == nullptr)
	{
		return;
	}
	RecursePrintList(head->pNext);
	cout << head->m_nValue << " ";
}

int main()
{
	int tmp;
	ListNode* Head = nullptr; \
		ListNode* Prenode = nullptr;;
	while (cin>>tmp)
	{
		ListNode* Tmpnode = new ListNode;
		Tmpnode->m_nValue = tmp;
		Tmpnode->pNext = nullptr;
		if (Head == nullptr)
		{
			Head = Tmpnode;
			Prenode = Head;
		}
		else
		{
			Prenode->pNext = Tmpnode;
			Prenode = Tmpnode;
		}
		if (cin.get() == '\n')
		{
			break;
		}
	}
	//ReversePrintList(Head);
	RecursePrintList(Head);
	system("pause");
    return 0;
}

