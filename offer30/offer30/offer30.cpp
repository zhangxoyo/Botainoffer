// offer30.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stack>

using std::stack;

template<typename T>
class StackWithMin
{
public:
	void pop();
	T top();
	void push(const T& value);
	T min();
private:
	stack<T> m_data;
	stack<T> m_min;
};

template<typename T> void StackWithMin<T>::push(const T& value)
{
	m_data.push(value);
	if (m_min.size == 0 ||value < m_min.top() )
	{
		m_min.push(value);
	}
	else
	{
		m_min.push(m_min.top());
	}
}

template<typename T> void StackWithMin<T>::pop()
{
	m_data.pop();
	m_min.pop();
}

template<typename T> T StackWithMin<T>::min()
{
	return m_min.top();
}

template<typename T> T StackWithMin<T>::top()
{
	return m_data.top();
}


int main()
{
    return 0;
}

