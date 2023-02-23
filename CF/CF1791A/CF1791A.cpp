#include <bits/stdc++.h>

using std::cin;
using std::cout;

int T;
char ch;

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> ch;
		if (ch == 'c' or ch == 'o' or ch == 'd' or ch == 'd' or ch == 'f' or
			ch == 'r' or ch == 'e' or ch == 's')
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}

