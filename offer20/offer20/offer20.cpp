// offer20.cpp : �������̨Ӧ�ó������ڵ㡣
//��ʾ��ֵ���ַ���//����״̬��
//����λ-�������� -С����-С������-E|e-����λ-��������

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

