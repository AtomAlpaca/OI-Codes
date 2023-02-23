#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 2e5 + 5;

int T, i, n,ans;
std::string s;
char ch;
bool f[27];
int a[MAX], b[MAX];

void clear()
{
	for (int i = 0; i <= 25; ++i)
	{
		f[i] = false;
	}
}

void clearA()
{
	for (int i = 0; i <= n + 1; ++i)
	{
		a[i] = 0;
	}
}

void clearB()
{
	for (int i = 0; i <= n + 1; ++i)
	{
		b[i] = 0;
	}
}

void solve()
{
	cin >> n >> s;
	clear();
	clearA();
	for (int i = 1; i <= n; ++i)
	{
		a[i] = a[i - 1];
		if (!f[s[i - 1] - 'a'])
		{
			++a[i];
			f[s[i - 1] - 'a'] = true;
		}
	}
	clear();
	clearB();
	for (int i = n; i >= 1; --i)
	{
		b[i] = b[i + 1];
		if (!f[s[i - 1] - 'a'])
		{
			++b[i];
			f[s[i - 1] - 'a'] = true;
		}
	} 
	ans = 0;
	for (int i = 1; i < n; ++i)
	{
		ans = std::max(ans, a[i] + b[i + 1]);
	}
	cout << ans << '\n';
}

int main()
{
	cin >> T;
	while (T--)
	{
		solve();
	}
}

