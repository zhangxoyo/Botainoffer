// offer8.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

using namespace std;

struct TreeNode
{
	int nValue;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;

};

TreeNode* GetNextInMidOrder(TreeNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	if (node->right != nullptr)
	{
		TreeNode* tmpNode = node->right;

		while (tmpNode->left!= nullptr)
		{
			tmpNode = tmpNode->left;
		}
		return tmpNode;
	}
	else
	{
		TreeNode* parent = node->parent;
		if (parent == nullptr)
		{
			return nullptr;
		}
		if (node == parent->left)
		{
			return parent;
		}
		else
		{
			TreeNode* grandparent = parent->parent;
			while (grandparent!= nullptr)
			{
				if (parent == grandparent->left)
				{
					return grandparent;
				}
				grandparent = grandparent->parent;
			}
			
			return nullptr;
			
			
		}
	}
}

int main()
{
    return 0;
}

