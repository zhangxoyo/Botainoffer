// offer36.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

struct Node
{
	int val;
	Node* left;
	Node* right;
};

class Solution {
public:
	Node* TransTree2List(Node* pNode, Node** pListNode)
	{
		if (pNode == nullptr)
		{
			return nullptr;
		}

		if (pNode->left != nullptr)
		{
			TransTree2List(pNode->left, pListNode);
		}

		if (*pListNode != nullptr)
		{
			(*pListNode)->right = pNode;
		}
		pNode->left = (*pListNode);
		*pListNode = pNode;

		if (pNode->right != nullptr)
		{
			TransTree2List(pNode->right, pListNode);
		}
	}

	Node* treeToDoublyList(Node* root)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		Node* pListNode = nullptr;
		TransTree2List(root, &pListNode);

		while (pListNode != nullptr &&pListNode->left != nullptr)
		{
			pListNode = pListNode->left;
		}
		return pListNode;

	}



};



Node* TransTree2List(Node* pNode, Node** pListNode)
{
	if (pNode == nullptr)
	{
		return nullptr;
	}

	if (pNode->left != nullptr)
	{
		TransTree2List(pNode->left, pListNode);
	}

	if (*pListNode != nullptr)
	{
		(*pListNode)->right = pNode;
	}
	pNode->left = (*pListNode);
	*pListNode = pNode;

	if (pNode->right != nullptr)
	{
		TransTree2List(pNode->right, pListNode);
	}
}

Node* Convert(Node* pHead)
{
	if (pHead == nullptr)
	{
		return nullptr;
	}
	Node* pListNode = nullptr;
	TransTree2List(pHead, &pListNode);

	while (pListNode != nullptr &&pListNode->left != nullptr)
	{
		pListNode = pListNode->left;
	}
	return pListNode;
}

int main()
{
    return 0;
}

