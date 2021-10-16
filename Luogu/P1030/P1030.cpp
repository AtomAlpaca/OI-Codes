#include <bits/stdc++.h>
using namespace std;

void Ans(string str1,string str2)
{
	if (str1.length() == 0)
	{
		return ;
	}
	cout << str2[str2.length() - 1];
	Ans(str1.substr(0,str1.find(str2[str2.length() - 1])),str2.substr(0,str1.find(str2[str2.length() - 1])));
	Ans(str1.substr(str1.find(str2[str2.length() - 1]) + 1),str2.substr(str1.find(str2[str2.length() - 1]),str1.length() - str1.find(str2[str2.length() - 1]) - 1));
	return ;
}

int main(int argc, char const *argv[])
{
	string str1,str2;
	cin >> str1 >> str2;
	Ans(str1,str2);
	return 0;
}