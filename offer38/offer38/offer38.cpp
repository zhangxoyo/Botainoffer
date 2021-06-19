// offer38.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<set>
using std::cout;
using std::endl; 
using std::cin;
using namespace std;
void Permutation(char* pStr, char* pBegin)
{
	if (*pBegin == '\0')
	{
		cout << pStr << endl;
	}
	else
	{
		for (char* pCh = pBegin; *pCh != '\0'; ++pCh)
		{
			char tmp = *pCh;
			*pCh = *pBegin;
			*pBegin = tmp;
			Permutation(pStr, pBegin + 1);
			tmp = *pCh;
			*pCh = *pBegin;
			*pBegin = tmp;

		}
	}
}

void Permutation(char* pStr)
{
	if (pStr == nullptr)
		return;

	char* pTmp = pStr;
	Permutation(pStr, pTmp);
}

class Solution {
public:
	set<string> store;
	vector<string> ret;

	void dfs(string& s, string& cur, vector<bool>& used) {
		if (cur.size() == s.size()) {
			store.insert(cur);
			return;
		}
		for (int i = 0; i < s.size(); ++i) {
			if (used[i]) continue;
			cur += s[i];
			used[i] = true;
			dfs(s, cur, used);
			used[i] = false;
			cur.pop_back();
		}
	}

	vector<string> permutation(string s) {
		string cur = "";
		vector<bool> used(s.size(), false);
		dfs(s, cur, used);

		for (auto& ele : store) ret.push_back(ele);
		return ret;
	}
};


int main()
{
	std::string str;
	getline(cin, str);
	Solution s;
	s.permutation(str);
	//Permutation(const_cast<char*>(str.c_str()));
	system("pause");
    return 0;
}

