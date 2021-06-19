// offer32.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<deque>

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

using std::deque;
using std::cout;
using std::endl;
void PrintTree(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;
	deque<BinaryTreeNode*> dequeTreeNode;
	dequeTreeNode.push_back(pRoot);

	while (dequeTreeNode.size() != 0)
	{
		BinaryTreeNode* tmpNode = dequeTreeNode.front();
		cout << tmpNode->m_nValue<< " ";
		if (tmpNode->m_pLeft != nullptr)
		{
			dequeTreeNode.push_back(tmpNode->m_pLeft);
		}
		if (tmpNode->m_pRight != nullptr)
		{
			dequeTreeNode.push_back(tmpNode->m_pRight);
		}
		dequeTreeNode.pop_front();
	}
}

void PrintTreeMulLine(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;
	deque<BinaryTreeNode*> queueTreeNode;
	queueTreeNode.push_back(pRoot);

	int nNextLevel = 0;
	int nCurrent = 1;
	while (queueTreeNode.size() != 0)
	{
		BinaryTreeNode* tmp = queueTreeNode.front();
		cout << tmp->m_nValue << " ";
		nCurrent--;
		if (tmp->m_pLeft != nullptr)
		{
			queueTreeNode.push_back(tmp->m_pLeft);
			nNextLevel++;
		}
		if (tmp->m_pRight != nullptr)
		{
			queueTreeNode.push_back(tmp->m_pRight);
			nNextLevel++;
		}
		queueTreeNode.pop_front();
		if (nCurrent == 0)
		{
			cout << endl;
			nCurrent = nNextLevel;
			nNextLevel = 0;
		}
	}
}

void PrintTree3(BinaryTreeNode* pRoot)
{

}

int main()
{
    return 0;
}

