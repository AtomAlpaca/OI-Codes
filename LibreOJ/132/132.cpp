#include <iostream>

using std::cin;
using std::cout;

long long n, q, op, x, y, c;
long long a[1000005], d[2700055], lazy[2700055];

void build(long long l, long long r, long long p)
{
	if (l == r)
	{
		d[p] = a[l];
		return ;
	}
	long long k = l + ((r - l) >> 1);
	build(l, k, p << 1);
	build(k + 1, r, (p << 1) + 1);
	d[p] = d[p << 1] + d[(p << 1) + 1];
	return ;
}

void update(long long l, long long r, long long c, long long s, long long t, long long p)
{
	if (l <= s and r >= t)
	{
		d[p] += c * (t - s + 1);
		lazy[p] += c;
		return ;
	}
	
	long long k = s + ((t - s) >> 1);

	if (lazy[p] and s != t)
	{
		lazy[p << 1] += lazy[p];
		lazy[(p << 1) + 1] += lazy[p];
		d[p << 1] += lazy[p] * (k - s + 1);
		d[(p << 1) + 1] += lazy[p] * (t - k);
		lazy[p] = 0;
	}

	if (l <= k)
	{
		update(l, r, c, s, k, p << 1);
	}
	if (r > k)
	{
		update(l, r, c, k + 1, t, (p << 1) + 1);
	}
		
	d[p] = d[p << 1] + d[(p << 1) + 1];
	return ;
}

long long getsum(long long l, long long r, long long s, long long t, long long p)
{
	if (l <= s and r >= t)
	{
		return d[p];
	}

	long long k = s + ((t - s) >> 1);

	if (lazy[p])
	{
		lazy[p << 1] += lazy[p];
		lazy[(p << 1) + 1] += lazy[p];
		d[p << 1] += lazy[p] * (k - s + 1);
		d[(p << 1) + 1] += lazy[p] * (t - k);
		lazy[p] = 0;
	}

	long long q = 0;
	if (l <= k)
	{
		q += getsum(l, r, s, k, p << 1);
	}
	if (r > k)
	{
		q += getsum(l, r, k + 1, t, (p << 1) + 1);
	}

	return q;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> q;
	
	for (long long i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	build(1, n, 1);

	while (q--)
	{
		cin >> op >> x >> y;
		if (op == 1)
		{
			cin >> c;
			update(x, y, c, 1, n, 1);
		}
		else
		{
			cout << getsum(x, y, 1, n, 1) << '\n';
		}
	}
	return 0;
}
