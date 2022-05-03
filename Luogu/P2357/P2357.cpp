nclude <iostream>

using std::cin;
using std::cout;

long long n, m, op, x, y, z;
long long a[200005], d[1000005], laz[1000005];

void pushup(long long p)
{
	d[p] = d[p << 1] + d[(p << 1) + 1];
	return ;
}

void pushdown(long long l, long long r, long long p)
{
	long long k = l + ((r - l) >> 1);
	laz[p << 1] += laz[p];
	laz[(p << 1) + 1] += laz[p];
	d[p << 1] += (k - l + 1) * laz[p];
	d[(p << 1) + 1] += (r - k) * laz[p];
	laz[p] = 0;
	return ;
}

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
	
	pushup(p);

	return ;
}

void update(long long l, long long r, long long c, long long s, long long t, long long p)
{
	if (l <= s and r >= t)
	{
		d[p] += (t - s + 1) * c;
		laz[p] += c;
		return ;
	}

	long long k = s + ((t - s) >> 1);

	if (laz[p])
	{
		pushdown(s, t, p);
	}

	if (l <= k)
	{
		update(l, r, c, s, k, p << 1);
	}
	if (r > k)
	{
		update(l, r, c, k + 1, t, (p << 1) + 1);
	}

	pushup(p);

	return ;
}

long long getsum(long long l, long long r, long long s, long long t, long long p)
{
	if (l <= s and r >= t)
	{
		return d[p];
	}

	long long k = s + ((t - s) >> 1);

	if (laz[p])
	{
		pushdown(s, t, p);
	}
	
	long long sum = 0;

	if (l <= k)
	{
		sum += getsum(l, r, s, k, p << 1);
	}
	if (r > k)
	{
		sum += getsum(l, r, k + 1, t, (p << 1) + 1);
	}

	pushup(p);

	return sum ;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;
	for (long long i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	build(1, n, 1);

	while (m--)
	{
		cin >> op;
		if (op == 1)
		{
			cin >> x >> y >> z;
			update(x, y, z, 1, n, 1);
		}
		else if (op == 2)
		{
			cin >> x;
			update(1, 1, x, 1, n, 1);
		}
		else if (op == 3)
		{
			cin >> x;
			update(1, 1, (-x), 1, n, 1);
		}
		else if (op == 4)
		{
			cin >> x >> y;
			cout << getsum(x, y, 1, n, 1) << '\n';
		}
		else
		{
			cout << getsum(1, 1, 1, n, 1) << '\n';
		}
	}
	return 0;
}

