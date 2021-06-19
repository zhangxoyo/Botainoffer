// offer17.cpp : 定义控制台应用程序的入口点。
//输入数字n，按顺序打印出从1到最大的n位数十位数。

#include "stdafx.h"
#include<iostream>

bool Increase(char* szNumbers, int n)
{
	int nOverSize = 1;

	for (int i = n - 1; i >= 0; i--)
	{
		int nTmp = szNumbers[i] - '0' + nOverSize;
		if (nTmp >= 10)
		{
			if (i == 0)
			{
				return true;
			}
			else
			{
				szNumbers[i] = '0' + nTmp - 10;
			}
		}
		else
		{
			szNumbers[i] = szNumbers[i] + 1;
			return false;
		}
	}
}

int main()
{
	int n;
	std::cin >> n;
	char* szNumbers = new char[n + 1];
	/*for (int i = 0; i <= n; i++)
	{
		szNumbers[i] = '0';
	}*/
	memset(szNumbers, '0',n);
	szNumbers[n] = '\0';
	printf("\n\n\n\n");
	while (!Increase(szNumbers, n))
	{
		//printf("%s\n", szNumbers);
		int nLength = strlen(szNumbers);
		for (int i = 0; i < nLength; i++)
		{
			if (szNumbers[i] == '0')
				continue;
			else
			{
				char* szTmp = szNumbers;
				printf("%s\n", szTmp + i);
				break;
			}
		}
	}

	
	system("pause");
    return 0;
}

