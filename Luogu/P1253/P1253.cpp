#include <iostream>

using std::cin;
using std::cout;

const long long MAX = 1e18 + 5;
long long n, m, op, x, y, z;
long long a[1000005], d[4500005], add[4500005], cov[4500005];

void pushup(long long p)
{
	d[p] = std::max(d[p << 1], d[(p << 1) + 1]);
	return ;
}

void pushdown(long long l, long long r, long long p)
{
	if (cov[p] != MAX)
	{
		add[p << 1] = 0;
		add[p << 1 | 1] = 0;
		d[p << 1] = cov[p];
		d[(p << 1) + 1] = cov[p];
		cov[p << 1] = cov[p];
		cov[(p << 1) + 1] = cov[p];
		cov[p] = MAX;
	}
	if (add[p])
	{
		int k = l + ((r - l) >> 1);
		d[p << 1] += add[p];
		d[p << 1 | 1] += add[p];
		add[p << 1] += add[p];
		add[(p << 1) + 1] += add[p];
		add[p] = 0;
	}

	return;
}

void build(int l, int r, int p)
{
	cov[p] = MAX;
	if (l == r)
	{
		d[p] = a[l];
		return ;
	}

	int k = l + ((r - l) >> 1);

	build(l, k, p << 1);
	build(k + 1, r, (p << 1) + 1);

	pushup(p);

	return ;
}

void update(int l, int r, int c, int s, int t, int p)
{
	if (l <= s and r >= t)
	{
		d[p] += c;
		add[p] += c;
		return ;
	}

	int k = s + ((t - s) >> 1);
	
	pushdown(s, t, p);
	if (l <= k)
	{
		update(l, r, c, s, k, p << 1);
	}
	
	if (r > k)
	{
		update(l, r, c, k + 1, t, (p << 1) + 1);
	}

	pushup(p);
}


void update2(int l, int r, int c, int s, int t, int p)
{
	if (l <= s and r >= t)
	{
		d[p] = c;
		cov[p] = c;
		add[p] = 0;
		return ;
	}

	int k = s + ((t - s) >> 1);
	
	pushdown(s, t, p);
	
	if (l <= k)
	{
		update2(l, r, c, s, k, p << 1);
	}
	if (r > k)
	{
		update2(l, r, c, k + 1, t, (p << 1) + 1);
	}

	pushup(p);

	return ;
}

long long getnum(int l, int r, int s, int t, int p)
{
	if (l <= s and r >= t)
	{
		return d[p];
	}

	int k = s + ((t - s) >> 1);
	pushdown(s, t, p);
	long long num = -MAX;

	if (l <= k)
	{
		num = std::max(num, getnum(l, r, s, k, p << 1));
	}
	if (r > k)
	{
		num = std::max(num, getnum(l, r, k + 1, t, (p << 1) + 1));
	}

	return num;
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
			cin >> z;
			update2(x, y, z, 1, n, 1);
		}
		else if (op == 2)
		{
			cin >> z;
			update(x, y, z, 1, n, 1);
		}
		else
		{
			cout << getnum(x, y, 1, n, 1) << '\n';
		}
	}

	return 0;
}


