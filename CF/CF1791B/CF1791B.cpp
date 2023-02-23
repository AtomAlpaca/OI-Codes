#include <bits/stdc++.h>

using std::cin;
using std::cout;

int T, x, y, n;
std::string str;
char ch;

void solve()
{
	x = y = 0;
	cin >> n >> str;
	for (int i = 0; i < n; ++i)
	{
		if (str[i] == 'U')
		{
			++y;
		}
		else if (str[i] == 'D')
		{
			--y;
		}
		else if (str[i] == 'L')
		{
			--x;
		}
		else if (str[i] == 'R')
		{
			++x;
		}
		if (x == 1 and y == 1)
		{
			cout << "YES\n";
			return ;
		}
	}
	cout << "NO\n";
}

int main()
{
	cin >> T;
	while (T--)
	{
		solve();
	}
}

