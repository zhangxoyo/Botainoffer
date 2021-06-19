// offer29.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void PrintMatrix(int** p, int start, int end)
{
	if (end < start)
	{
		return;
	}
	if (start == end)
	{
		cout << p[start][end] << " ";
		return;
	}

	for (int i = start; i <= end; i++)
	{
		cout << p[start][i] << " ";
	}
	for (int i = start + 1; i <= end; i++)
	{
		cout << p[i][end] << " ";
	}

	for (int i = end - 1; i >= start; i--)
	{
		cout << p[end][i] << " ";
	}

	for (int i = end - 1; i > start; i--)
	{
		cout << p[i][start] << " ";
	}
	PrintMatrix(p, ++start, --end);
	return;
}

int main()
{
	int n;
	cin >> n;
	int **p = new int*[n];

	for (int i = 0; i < n; i++)
	{
		p[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cin >> p[i][j];
		}
	}
	PrintMatrix(p, 0, n - 1);
	system("pause");
    return 0;
}

