#include <iostream>

using std::cin;
using std::cout;

const int MAX = 1e5 + 5;

long long n, m, x, y, z, op;
long long a[MAX], st[MAX << 2], mx[MAX << 2];

void pu(long long x)
{
	st[x] = st[x << 1] + st[x << 1 | 1];
	mx[x] = std::max(mx[x << 1], mx[x << 1 | 1]);
	return ;
}

void build(int l, int r, int x)
{
	if (l == r)
	{
		st[x] = mx[x] = a[l];
		return ;
	}
	int k = l + ((r - l) >> 1);
	build(l, k, x << 1); build(k + 1, r, x << 1 | 1);
	pu(x);
}

void change(long long l, long long r, long long p, long long s, long long x)
{
	if (l == r and l == s)
	{
		st[x] = mx[x] = p;
		return ;
	}
	int k = l + ((r - l) >> 1);
	if (s <= k) { change(l, k, p, s, x << 1); }
	if (s >  k) { change(k + 1, r, p, s, x << 1 | 1); };
	pu(x);
	return ;
}

void mod(long long l, long long r, long long p, long long s, long long t, long long x)
{
	if (l >= s and r <= t and mx[x] < p) { return ; }
	if (l == r)
	{
		mx[x] %= p; st[x] %= p;
		return ;
	}
	int k = l + ((r - l) >> 1);
	if (s <= k) { mod(l, k, p, s, t, x << 1); }
	if (t >  k) { mod(k + 1, r, p, s, t, x << 1 | 1); };
	pu(x);
	return ;
}

long long sum(long long l, long long r, long long s, long long t, long long x)
{
	if (l >= s and r <= t) { return st[x]; }
	long long k = l + ((r - l) >> 1), tmp = 0;
	if (s <= k) { tmp += sum(l, k, s, t, x << 1); }
	if (t >  k) { tmp += sum(k + 1, r, s, t, x << 1 | 1); };
	return tmp;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	build(1, n, 1);

	while (m--)
	{
		cin >> op >> x >> y;
		if 		(op == 1) { cout << sum(1, n, x, y, 1) << '\n'; }
		else if (op == 2) { cin >> z; mod(1, n, z, x, y, 1); }
		else			  { change(1, n, y, x, 1); };
	}

	return 0;
}
