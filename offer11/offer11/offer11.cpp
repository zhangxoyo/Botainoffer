// offer11.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<memory>
using namespace std;

int FindMin(int* p, int start, int end);

int main()
{
	

	while (1)
	{
		int n;
		cin >> n;
		unique_ptr<int[]> spNumbers(new int[n]);
		for (int i = 0; i < n; i++)
		{
			cin >> spNumbers[i];
		}

		int nmin = FindMin(spNumbers.get(), 0, n - 1);

		if (nmin >= 0)
		{
			cout << "min : " << spNumbers[nmin] << endl;
		}
		else
		{
			cout << "error occur" << endl;
		}
		system("pause");
	}
	
    return 0;
}

int FindMin(int* p, int start, int end)
{
	//若start center end相同 11101，则顺序查找，复杂度O(n)
	if (start > end)
		return -1;
	if (p[start] < p[end])
		return start;
	if (end - start == 1)
	{
		return p[start] > p[end] ? end : start;
	}
	int center = (start + end) / 2;
	if (p[start] > p[center])
	{
		return FindMin(p, start, center);
	}
	else if (p[start] < p[center])
	{
		return FindMin(p, center+1, end);
		
	}
	else
		return start;
}
