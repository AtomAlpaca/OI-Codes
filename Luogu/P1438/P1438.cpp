#include <iostream>

using std::cin;
using std::cout;

const int MAX = 1e5 + 5;

long long n, m, q, u, v, c, d;
long long f[MAX << 2], g[MAX << 2], a[MAX], e[MAX];

void build(int l, int r, int x)
{
	if (l == r)
	{
		f[x] = a[l];
		return ;
	}

	int k = l + ((r - l) >> 1);

	build(l, k, x << 1);
	build(k + 1, r, x << 1 | 1);

	f[x] = f[x << 1] + f[x << 1 | 1];
	return ;
}

void pd(int l, int r, int x)
{
	if (!g[x])
	{
		return ;
	}

	int k = l + ((r - l) >> 1);

	g[x << 1] += g[x], g[x << 1 | 1] += g[x];
	f[x << 1] += g[x] * (k - l + 1);
	f[x << 1 | 1] += g[x] * (r - k);
	g[x] = 0;
	return ;
}

void add(int l, int r, int x, int s, int t, int y)
{
	if (l >= s and r <= t)
	{
		g[x] += y;
		f[x] += y * (r - l + 1);
		return ;
	}

	pd(l, r, x);
	int k = l + ((r - l) >> 1);

	if (s <= k)
	{
		add(l, k, x << 1, s, t, y);
	}
	if (t > k)
	{
		add(k + 1, r, x << 1 | 1, s, t, y);
	}

	f[x] = f[x << 1] + f[x << 1 | 1];
	return ;
}

long long get(int l, int r, int x, int s, int t)
{
	if (l >= s and r <= t)
	{
		return f[x];
	}

	pd(l, r, x);
	long long k = l + ((r - l) >> 1), sum = 0;

	if (s <= k)
	{
		sum += get(l, k, x << 1, s, t);
	}
	if (t > k)
	{
		sum += get(k + 1, r, x << 1 | 1, s, t);
	}

	f[x] = f[x << 1] + f[x << 1 | 1];
	return sum;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> e[i];
	}

	for (int i = 1; i <= n; ++i)
	{
		a[i] = e[i] - e[i - 1];
	}

	build(1, n, 1);

	while (m--)
	{
		cin >> q;
		if (q == 1)
		{
			cin >> u >> v >> c >> d;
			add(1, n, 1, u, u, c);
			if (u + 1 <= v)
			{
				add(1, n, 1, u + 1, v, d);
			}
			if (v + 1 <= n)
			{
				add(1, n, 1, v + 1, v + 1, -(c + d * (v - u)));
			}
		}
		else
		{
			cin >> d;
			cout << get(1, n, 1, 1, d) << '\n';
		}
	}
	return 0;
}
