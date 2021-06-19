// offer26.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

bool Equal(int a, int b)
{
	//if (a - b > 0.0000001)
	if(a==b)
		return false;
	else
		return true;
}

bool IsSubTree(TreeNode* A, TreeNode* B)
{
	if (A == nullptr)
	{
		return false;
	}
	if (B == nullptr)
	{
		return true;
	}
	if (!Equal(A->val, B->val))
	{
		return false;
	}
	bool result = IsSubTree(A->left, B->left);
	if (result)
	{
		result = IsSubTree(A->right, B->right);
	}
	return result;
}

bool Find(TreeNode* A, TreeNode* B)
{
	bool result = false;
	if (A == nullptr || B == nullptr)
	{
		return false;
	}
	if (Equal(A->val, B->val))
	{
		result = IsSubTree(A, B);
	}
	
	if(!result)
		result = Find(A->left, B);
	if (!result)
		result = Find(A->right, B);

	return result;
	
}

int main()
{
    return 0;
}

