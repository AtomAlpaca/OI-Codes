#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string str;
	cin >> str;
	for (int i = 0,len = str.length(); i < len; ++i)
	{
		if (str[i] >= 'a' and str[i] <= 'z')
		{
			cout << char(str[i] + 'A' - 'a');
		}
		else
		{
			cout << str[i];
		}
	}
	return 0;
}