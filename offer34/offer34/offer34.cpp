// offer34.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void FindPathRecursive(BinaryTreeNode* pRoot, int ToBeSum, int curSum, vector<int> path)
{
	if (pRoot == nullptr)
		return;

	curSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);
	bool isLeaf = pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr;
	if (curSum == ToBeSum && isLeaf)
	{
		for (auto i : path)
		{
			cout << i << " ";
		}

	}

	if (pRoot->m_pLeft != nullptr)
	{
		FindPathRecursive(pRoot->m_pLeft, ToBeSum, curSum, path);
	}
	if (pRoot->m_pRight != nullptr)
	{
		FindPathRecursive(pRoot->m_pRight, ToBeSum, curSum, path);
	}

	//if (isLeaf)
	//{
		path.pop_back();
	//}
}

void FindPath(BinaryTreeNode* pRoot, int ToBeSum)
{
	if (pRoot == nullptr)
		return;
	int CurrentSum = 0;
	vector<int> path;
	FindPathRecursive(pRoot, ToBeSum, CurrentSum, path);
}

int main()
{
    return 0;
}

