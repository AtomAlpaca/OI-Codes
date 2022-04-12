#include <iostream>

using std::cin;
using std::cout;

int n, m, op, x, y;
long long a[500005], d[2000005], lazy[2000005];

void build(int l, int r, int p)
{
	if (l == r)
	{
		d[p] = a[l];
		return ;
	}
	int k = l + ((r - l) >> 1);
	build(l, k, p << 1);
	build(k + 1, r, (p << 1) + 1);
	d[p] = d[p << 1] + d[(p << 1) + 1];
	return ;
}

void update(int l, int r, int c, int s, int t, int p)
{
	if (l <= s and r >= t)
	{
		d[p] += c * (t - s + 1);
		lazy[p] += c;
		return ;
	}

	int k = s + ((t - s) >> 1);

	if (s != t and lazy[p])
	{
		d[p << 1] += lazy[p] * (k - s + 1);
		d[(p << 1) + 1] += lazy[p] * (t - s);
		lazy[p << 1] += lazy[p];
		lazy[(p << 1) + 1] += lazy[p];
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

int getsum(int l, int r, int s, int t, int p)
{
	if (l <= s and r >= t)
	{
		return d[p];
	}

	int sum = 0;
	int k = s + ((t - s) >> 1);
	
	if (lazy[p])
	{
		d[p << 1] += lazy[p] * (k - s + 1);
		d[(p << 1) + 1] += lazy[p] * (t - s);
		lazy[p << 1] += lazy[p];
		lazy[(p << 1) + 1] += lazy[p];
		lazy[p] = 0;
	}

	if (l <= k)
	{
		sum += getsum(l, r, s, k, p << 1);
	}

	if (r > k)
	{
		sum += getsum(l, r, k + 1, t, (p << 1) + 1);
	}

	return sum;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	build(1, n, 1);

	while (m--)
	{
		cin >> op >> x >> y;
		if (op == 1)
		{
			update(x, x, y, 1, n, 1);
		}
		else
		{
			cout << getsum(x, y, 1, n, 1) << '\n';
		}
	}
	return 0;
}
