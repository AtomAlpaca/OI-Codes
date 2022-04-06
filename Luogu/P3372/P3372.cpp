#include <iostream>

using std::cin;
using std::cout;

long long m, n, x, y, h, tmp;
long long nums[100005], d[270000], lazy[270000];

void build(long long l, long long r, long long p)
{
	if (l == r)
	{
		d[p] = nums[l];
		return ;
	}
	long long k = l + ((r - l) >> 1);
	build(l, k, p * 2);
	build(k + 1, r, p * 2 + 1);
	d[p] = d[p * 2] + d[p * 2 + 1];
	return ;
}

void update(long long l, long long r, long long c, long long s, long long t, long long p)
{
	if (l <= s and r >= t)
	{
		d[p] += (t - s + 1) * c;
		lazy[p] += c;
		return ;
	}

	long long k = s + ((t - s) >> 1);

	if (lazy[p] and s != t)
	{
		d[p * 2] += lazy[p] * (k - s + 1);
		d[p * 2 + 1] += lazy[p] * (t - k);
		lazy[p * 2] += lazy[p];
		lazy[p * 2 + 1] += lazy[p];
		lazy[p] = 0;
	}

	if (l <= k)
	{
		update(l, r, c, s, k, p * 2);
	}
	if(r > k)
	{
		update(l, r, c, k + 1, t, p * 2 + 1);
	}

	d[p] = d[p * 2] + d[p * 2 + 1];
    return ;
}

long long getSum(long long l, long long r, long long s, long long t, long long p)
{
	if (l <= s and r >= t)
	{
		return d[p];
	}
	
	long long k = s + ((t - s) >> 1);
	if (lazy[p])
	{
		d[p * 2] += lazy[p] * (k - s + 1);
		d[p * 2 + 1] += lazy[p] * (t - k);
		lazy[p * 2] += lazy[p];
		lazy[p * 2 + 1] += lazy[p];
		lazy[p] = 0;
	}

	long long q = 0;

	if (l <= k)
	{
		q += getSum(l, r, s, k, p * 2);
	}
	if (r > k)
	{
		q += getSum(l, r, k + 1, t, p * 2 + 1);
	}
	return q;

}

int main()
{
	cin >> n >> m;
	for (long long i = 1; i <= n; ++i)
	{
		cin >> nums[i];
	}
	build(1, n, 1);

	while (m--)
	{
		cin >> tmp >> x >> y;
		if (tmp == 1)
		{
			cin >> h;
			update(x, y, h, 1, n, 1);
		}
		else
		{
			cout << getSum(x, y, 1, n, 1) << '\n';
		}
	}
	
	return 0;
}
