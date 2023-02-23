#include <bits/stdc++.h>

using std::cin;
using std::cout;

int T, i, n;
std::string s;
char ch;
void solve()
{
	cin >> n >> s;
	const int len = s.size();
	for (i = 0; i < len / 2; ++i)
	{
		if (s[i] == s[len - i - 1])
		{
			break;
		}
	}

	cout << len - (2 * i) << '\n';
}

int main()
{
	cin >> T;
	while (T--)
	{
		solve();
	}
}

