// offer20.cpp : 定义控制台应用程序的入口点。
//表示数值的字符串//有限状态机
//符号位-整数部分 -小数点-小数部分-E|e-符号位-整数部分

#include "stdafx.h"
#include<iostream>
#include<string>
#include<string.h>
bool ScanUnSignedInteger(const char** str)
{
	const char* tmp = *str;
	while (**str != '\0' && **str >= '0' && **str <= '9')
		++(*str);
	return *str > tmp;
}

bool ScanInteger(const char** str)
{
	if (**str == '+' || **str == '-')
		++(*str);
	return ScanUnSignedInteger(str);
}


int main()
{
	using std::string;

	string str;
	getline(std::cin, str);
	int nIndex = 0;
	while (str[nIndex] == ' ')
	{
		str = str.substr(1, str.length() - 1);
	}
	int nLength = str.length();
	while (str[nLength-1] == ' ')
	{
		str = str.substr(0, str.length() - 1);
		nLength = str.length();
	}
	if (str.empty())
	{
		return false;
	}
	const char* sz = str.c_str();
	int numeric = ScanInteger(&sz);

	if (*sz == '.')
	{
		sz++;
		numeric = ScanUnSignedInteger(&sz);
	}
	if (*sz == 'e' || *sz == 'E')
	{
		sz++;
		numeric = ScanInteger(&sz)&& numeric;
	}
	return numeric&&*sz == '\0';
}

