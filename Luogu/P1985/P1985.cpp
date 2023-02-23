#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int INF = 0x3f3f3f3f;

int ans = INF, m, n, x;
int s[17], t[17], a[17], p[17];

int f(int x)
{
	int tmp = 0;
	while (x)
	{
		if (x & 1)
		{
			++tmp;
		}
		x >>= 1;
	}
	return tmp;
}

void c(int i, int j)
{
	t[i - 1] ^= (1 << (j - 1));
	t[i]	 ^= (1 << j);
	t[i]	 ^= (1 << (j - 1));
	if (j >= 2)
	{
		t[i] ^= (1 << (j - 2));
	}
	t[i + 1] ^= (1 << (j - 1));
	return ;
}

void g(int x)
{
	int tmp = 0;
	for (int i = 1; i <= m; ++i)
	{
		p[i] = 0;
		t[i] = s[i];
	}
	p[1] = x;
	for (int i = 1; i <= n; ++i)
	{
		if (x & (1 << (i - 1)))
		{
			c(1, i);
		}
	}

	for (int i = 1; i <= m - 1; ++i)
	{
		p[i + 1] = t[i];
		for (int j = 1; j <= n; ++j)
		{
			if (t[i] & (1 << (j - 1)))
			{
				c(i + 1, j);
			}
		}
	}

	if (t[m] & ((1 << n) - 1))
	{
		return ;
	}

	for (int i = 1; i <= m; ++i)
	{
		p[i] = p[i] & ((1 << n) - 1);
		tmp += f(p[i]);
	}

	if (tmp < ans)
	{
		ans = tmp;
		for (int i = 1; i <= m; ++i)
		{
			a[i] = p[i];
		}
		return ;
	}

	return ;
}

int main()
{
	cin >> m >> n;

	for (int i = 1; i <= m; ++i)
	{
		s[i] = 0;
		for (int j = 1; j <= n; ++j)
		{
			cin >> x;
			s[i] = s[i] << 1 | x;
		}
		a[i] = (1 << n) - 1;
	}

	for (int i = 0; i <= (1 << n) - 1; ++i)
	{
		g(i);
	}

	if (ans == INF)
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (a[i] & (1 << (n - j)))
				{
					cout << 1 << ' ';
				}
				else
				{
					cout << 0 << ' ';
				}
			}
			cout << '\n';
		}
	}

	return 0;
}

