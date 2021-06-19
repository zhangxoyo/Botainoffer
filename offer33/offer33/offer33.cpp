// offer33.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

using std::cout;
using std::endl;
using std::cin;

bool IsSquenceOfBST(int * p, int nLength)
{
	if (p == nullptr)
	{
		return false;
	}


	int rootValue = p[nLength - 1];
	int i = 0;
	for (; i < nLength; i++)
	{
		if (p[i] > rootValue)
			break;
	}
	for (int j = i + 1; j < nLength - 1; j++)
	{
		if (p[j] < rootValue)
			return false;
	}
	bool left = true; 
	bool right = true;
	if (i != 0)
	{
		left = IsSquenceOfBST(p, i);
	}
	if (i != nLength - 1)
	{
		right = IsSquenceOfBST(p+i, nLength -i-1);
	}

	return left && right;
}

int main()
{
    return 0;
}

