#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 1e5 + 5;

long long n, m, u, v, q;
double w;
double f[MAX << 2], g[MAX << 2], h[MAX << 2], a[MAX];

void pu(int x)
{
	f[x] = f[x << 1] + f[x << 1 | 1];
	g[x] = g[x << 1] + g[x << 1 | 1];
	return ;
}

void pd(int l, int r, int x)
{
	if (!h[x])
	{
		return ;
	}
	int k = l + ((r - l) >> 1);
	h[x << 1] += h[x], h[x << 1 | 1] += h[x];
	g[x << 1] += 2 * h[x] * f[x << 1] + (k - l + 1) * h[x] * h[x];
	g[x << 1 | 1] += 2 * h[x] * f[x << 1 | 1] + (r - k) * h[x] * h[x];
	f[x << 1] += h[x] * (k - l + 1);
	f[x << 1 | 1] += h[x] * (r - k);
	h[x] = 0;
	return ;
}

void add(int l, int r, int x, int s, int t, double y)
{
	if (l >= s and r <= t)
	{
		g[x] += 2 * y * f[x] + (r - l + 1) * y * y;
		f[x] += y * (r - l + 1);
		h[x] += y;
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
	pu(x);
	return ;
}

double sum1(int l, int r, int x, int s, int t)
{	
	if (l >= s and r <= t)
	{
		return f[x];
	}

	pd(l, r, x);
	int k = l + ((r - l) >> 1);
	double sum = 0;

	if (s <= k)
	{
		sum += sum1(l, k, x << 1, s, t);
	}
	if (t > k)
	{
		sum += sum1(k + 1, r, x << 1 | 1, s, t);
	}
	pu(x);
	return sum;
}

double sum2(int l, int r, int x, int s, int t)
{	
	if (l >= s and r <= t)
	{
		return g[x];
	}

	pd(l, r, x);
	int k = l + ((r - l) >> 1);
	double sum = 0;

	if (s <= k)
	{
		sum += sum2(l, k, x << 1, s, t);
	}
	if (t > k)
	{
		sum += sum2(k + 1, r, x << 1 | 1, s, t);
	}
	pu(x);
	return sum;
}

double mid(int l, int r)
{
	return sum1(1, n, 1, l, r) / (r - l + 1);
}

double s(int l, int r)
{
	return sum2(1, n, 1, l, r) / (r - l + 1) - mid(l, r) * mid(l, r);
}

void build(int l, int r, int x)
{
	if (l == r)
	{
		f[x] = a[l];
		g[x] = a[l] * a[l];
		return ;
	}

	int k = l + ((r - l) >> 1);

	build(l, k, x << 1);
	build(k + 1, r, x << 1 | 1);
	pu(x);
	return ;
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	build(1, n, 1);

	cout << std::fixed << std::setprecision(4);

	while (m--)
	{
		cin >> q >> u >> v;
		if (q == 1)
		{
			cin >> w;
			add(1, n, 1, u, v, w);
		}
		else if (q == 2)
		{
			cout << mid(u, v) << '\n';
		}
		else
		{
			cout << s(u, v) << '\n';
		}
	}
	return 0;
}
