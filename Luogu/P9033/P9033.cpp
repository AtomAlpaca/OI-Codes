#include <bits/stdc++.h>

using std::cin;
using std::cout;

long long n, m, k, T;

int len(long long x)
{
	int cnt = 0;
	while (x)
	{
		++cnt;
		x /= 2;
	}
	return cnt;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--)
	{
		cin >> n >> k >> m;
		int lk = len(k), lm = len(m);
		if (lk > lm or n == 0)
		{
			cout << -1 << '\n';
			continue;
		}
		if (k > m)
		{
			if (n == 1)
			{
				cout << -1;
				continue;
			}
			cout << (1 << (lk - 1)) << ' ' << k - (1 << (lk - 1)) << ' ';
			n -= 2;
		}
		else
		{
			cout << k << ' ';
			--n;
		}
		if (n > 0)
		{
			while (n--)
			{
				cout << 0 << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}

