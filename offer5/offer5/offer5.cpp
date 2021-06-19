// offer5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<memory>
#include<string>

using namespace std;

int main()
{
	string str;
	getline(cin, str);

	int nLength = str.length();
	int nBlankNum = 0;
	for (int i = 0; i < nLength; i++)
	{
		if (str[i] == ' ')
		{
			nBlankNum++;
		}
	}
	char* newArray = new char[nBlankNum * 2 + nLength + 1];
	int j = 0;
	newArray[nBlankNum * 2 + nLength] = '\0';
	for (int i = nLength - 1; i >= 0; i--)
	{
		j = i + nBlankNum  * 2;
		if (str[i] == ' ')
		{
			//for (int j = i+ (nBlankNum-1) * 2; i < nBlankNum * 2 + 2; j++)
			j = i + (nBlankNum - 1) * 2;
			newArray[j++] = '%';
			newArray[j++] = '2';
			newArray[j++] = '0';
			nBlankNum--;
		}
		else
		{
			newArray[j] = str[i];
		}
	}
	
	cout << newArray <<endl;
	system("pause");

    return 0;
}

