// offer31.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stack>

using std::cout;
using std::cin;
using std::endl;
using std::stack;

bool IsStackOut(int * p1, int* p2, int n)
{
	if (n == 0)
	{
		return false;
	}
	stack<int> stack1, stack2;
	stack1.push(p1[0]);
	int nIndex1 = 1;
	int nIndex2 = 0;
	while (stack1.size() >0 &&nIndex2 < n)
	{
		
		while (stack1.top() != p2[nIndex2] )
		{		
			stack1.push(p1[nIndex1]);
			nIndex1++;
		}
		if(stack1.top() == p2[nIndex2])
		{
 			stack1.pop();
			nIndex2++;
			//nIndex1++;
		}
		
	}

	return stack1.size() != 0 ? false : true;
	
}

int main()
{
	int n;
	cin >> n;
	int* p1 = new int[n];
	int* p2 = new int[n];


	while (true)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> p1[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> p2[i];
		}

		bool ret = IsStackOut(p1, p2, n);
		if (ret)
		{
			cout << " true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}
		system("pause");
	}
	
	
    return 0;
}

