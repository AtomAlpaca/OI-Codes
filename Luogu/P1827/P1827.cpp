#include <bits/stdc++.h>
using namespace std;

void Ans(string str1,string str2)
{
	if (str1.length() == 0)
	{
		return ;
	}
	Ans(str1.substr(0,str1.find(str2[0])),str2.substr(1,str1.find(str2[0])));
	Ans(str1.substr(str1.find(str2[0]) + 1),str2.substr(str1.find(str2[0]) + 1));
	cout << str2[0];
	return ;
}

int main(int argc, char const *argv[])
{
	string str1,str2;
	cin >> str1 >> str2;
	Ans(str1,str2);
	return 0;
}