// offer21.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<memory>

using std::cout;
using std::cin;
using std::endl;

void Sort(int * p, int n)
{
	int i = 0;
	int LastOdd = -1;
	int FirstEven = -1;
	while (i < n)
	{
		if (p[i] % 2)
		{
			LastOdd = i;
		}
		else
		{
			if(FirstEven  == -1)
				FirstEven = i;
		}
		if (LastOdd > FirstEven && FirstEven!= -1)
		{
			int tmp = p[FirstEven];
			p[FirstEven] = p[LastOdd];
			p[LastOdd] = tmp;
			int tmpOrder = LastOdd;
			LastOdd = FirstEven;
			FirstEven++;

		}
		i++;
	}
}

void Sort2(int * p, int n)
{
	int* pBegin = p;
	int* pEnd = p + n -1;

	while (pBegin < pEnd)
	{
		while (pBegin < pEnd && ((*pBegin)&0x01) == 1)
			pBegin++;

		while (pBegin < pEnd && ((*pEnd) & 0x1
			.) == 0)
			pEnd--;

		if (pBegin < pEnd)
		{
			int tmp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = tmp;
		}
	}

}

int main()
{
	int n;
	cin >> n;
	std::unique_ptr<int[]> spNumbers(new int[n]);

	for (int i = 0; i < n; i++)
	{
		cin >> spNumbers[i];
	}


	cout << "Before sort " << endl;
	for (int i = 0; i < n; i++)
	{
		cout<< spNumbers[i];
	}
	cout << endl;
	Sort2(spNumbers.get(), n);

	cout << "After sort " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << spNumbers[i];
	}
	cout << endl;
	system("pause");
    return 0;
}

