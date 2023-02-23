#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 1e5 + 5;
const int INF = 0x3f3f3f3f;

long long ans, n, m;
long long c[MAX], st[MAX << 2], laz[MAX << 2];

struct Line
{
	int p, q;
} f[MAX];

bool cmp(Line l1, Line l2)
{
	if (l1.q != l2.q)
	{
		return l1.q < l2.q;
	}
	return l1.p > l2.p;
}

long long min(long long x, long long y)
{
	if (x < y)
	{
		return x;
	}
	return y;
}

void pu(int x)
{
	st[x] = min(st[x << 1], st[x << 1 | 1]);
	return ;
}

void pd(int x)
{
	laz[x << 1] += laz[x], laz[x << 1 | 1] += laz[x];
	 st[x << 1] -= laz[x],  st[x << 1 | 1] -= laz[x];
	laz[x] = 0;
	return ;
}

void build(int l, int r, int x)
{
	if (l == r)
	{
		st[x] = c[l];
		return ;
	}

	int k = l + ((r - l) >> 1);
	build(l, k, x << 1);
	build(k + 1, r, x << 1 | 1);
	pu(x);
	return ;
}

void miu(int l, int r, int x, int s, int t)
{
	if (l >= s and r <= t)
	{
		++laz[x];
		--st[x];
		return ;
	}

	int k = l + ((r - l) >> 1);
	pd(x);
	if (s <= k)
	{
		miu(l, k, x << 1, s, t);
	}
	if (t > k)
	{
		miu(k + 1, r, x << 1 | 1, s, t);
	}
	pu(x);
	return ;
}

int get(int l, int r, int x, int s, int t)
{
	if (l >= s and r <= t)
	{
		return st[x];
	}

	pd(x);
	int k = l + ((r - l) >> 1), tmp = INF;
	if (s <= k)
	{
		tmp = std::min(tmp, get(l, k, x << 1, s, t));
	}
	if (t > k)
	{
		tmp = std::min(tmp, get(k + 1, r, x << 1 | 1, s, t));
	}
	pu(x);
	return tmp;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> c[i];
	}

	build(1, n, 1);

	for (int i = 1; i <= m; ++i)
	{
		cin >> f[i].p >> f[i].q;
	}

	std::sort(f + 1, f + m + 1, cmp);

	for (int i = 1; i <= m; ++i)
	{
		if (get(1, n, 1, f[i].p, f[i].q) > 0)
		{
			miu(1, n, 1, f[i].p, f[i].q);
			++ans;
		}
	}

	cout << ans;
	return 0;
}

