#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 1e5 + 5;

long long n, m, op, x, y;
long long a[MAX], st[MAX << 2], mx[MAX << 2];

void pu(int x)
{
	st[x] = st[x << 1] + st[x << 1 | 1];
	mx[x] = std::max(mx[x << 1], mx[x << 1 | 1]);
}

void build(int l, int r, int x)
{
	if (l == r) { mx[x] = st[x] = a[l]; return ; };
	int k = l + ((r - l) >> 1);
	build(l, k, x << 1); build(k + 1, r, x << 1 | 1);
	pu(x); return ;
}

long long sum(int l, int r, int s, int t, int x)
{
	if (l >= s and r <= t) { return st[x]; }
	long long k = l + ((r - l) >> 1), tmp = 0;
	if (k >= s) { tmp += sum(l, k, s, t, x << 1); }
	if (k <  t) { tmp += sum(k + 1, r, s, t, x << 1 | 1); }
	return tmp;
}

void sqr(int l, int r, int s, int t, int x)
{
	if (mx[x] <= 1) { return ; }
	if (l == r) { st[x] = std::floor(std::sqrt(st[x])); mx[x] = st[x]; return ; }
	int k = l + ((r - l) >> 1);
	if (k >= s) { sqr(l, k, s, t, x << 1); }
	if (k <  t) { sqr(k + 1, r, s, t, x << 1 | 1); }
	pu(x); return ;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	build(1, n, 1);
	cin >> m;
	while (m--)
	{
		cin >> op >> x >> y;
		if (x > y) { std::swap(x, y); }
		if (op) { cout << sum(1, n, x, y, 1) << '\n'; }
		else    { sqr(1, n, x, y, 1); }
	}
	return 0;
}
