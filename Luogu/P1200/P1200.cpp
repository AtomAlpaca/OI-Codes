#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string str1,str2;
	cin >> str1 >> str2;
	long long add1 = 1,add2 = 1;
	for (int i = 0,len = str1.length(); i < len; ++i)
	{
		add1 *= (str1[i] - 'A' + 1);
		add1 %= 47;
	}
	for (int i = 0,len = str2.length(); i < len; ++i)
	{
		add2 *= (str2[i] - 'A' + 1);
		add2 %= 47;
	}
	if (add1 == add2)
	{
		cout << "GO";
	}
	else
	{
		cout << "STAY";
	}
	return 0;
}