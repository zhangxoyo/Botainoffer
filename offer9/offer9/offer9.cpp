// offer9.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stack>
using namespace std;

template<typename T>
class CQueue
{
public:
	CQueue() ;
	~CQueue();

	void appendTail(const T& node);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T> CQueue<T>::CQueue()
{

}

template<typename T> CQueue<T>::~CQueue()
{

}

template<typename T> void CQueue<T>::appendTail(const T& node)
{
	stack1.push(node);
}

template<typename T> T CQueue<T>::deleteHead()
{
	if (stack2.empty())
	{ 
		while (!stack1.empty())
		{
			T node = stack1.top();
			stack1.pop();
			stack2.push(node);
		}
	} +-

	T Head = stack2.top();
	stack2.pop();
	return Head;
}

int main()
{
    return 0;
}

