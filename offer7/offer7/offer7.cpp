// offer7.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<string>

using namespace std;

struct TreeNode
{
	int nValue;
	TreeNode* left;
	TreeNode* right;
};
int preLeftbak = 0;
TreeNode* ConstructTree(string& preorder, int preLeft, int preright, string& midorder, int midleft, int midright)
{
	if (preLeft > preright || midleft > midright)
		return nullptr;
	int i = midleft;
	while (i <= midright)
	{
		if (midorder[i] == preorder[preLeft])
		{
			TreeNode * node = new TreeNode;
			node->nValue = midorder[i] - '0';
			node->left = node->right = nullptr;
			int leftLength = i - midleft;
			if(leftLength >0)
				node->left = ConstructTree(preorder, preLeft +1, preLeft + leftLength, midorder, midleft, i-1);
			if(leftLength <preright - preLeft)
			node->right = ConstructTree(preorder, preLeft + leftLength+1, preright, midorder, i + 1, midright);
			
			return node;
		}
		else
			i++;
	}
	return nullptr;
}

void LastOrderOutPut(TreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	else
	{
		LastOrderOutPut(node->left);
		LastOrderOutPut(node->right);
		cout << node->nValue << " ";
	}
}

void preOrderOutput(TreeNode* node)
{
	if (node == nullptr)
		return;
	else
	{
		cout << node->nValue << " ";
		preOrderOutput(node->left);
		preOrderOutput(node->right);
	}
}

void midOrderOutput(TreeNode* node)
{
	if (node == nullptr)
		return;
	else
	{
		
		preOrderOutput(node->left);
		cout << node->nValue << " ";
		preOrderOutput(node->right);
	}
}

int main()
{
	string preOrder, midOrder;
	getline(cin, preOrder);
	getline(cin, midOrder);

	if (preOrder.length() == 0 || midOrder.length() == 0)
	{
		cout << "bad input" << endl;
	}
	TreeNode* node = ConstructTree(preOrder, 0, preOrder.length()-1, midOrder, 0, midOrder.length()-1);
	LastOrderOutPut(node);
	system("pause");
    return 0;
}

