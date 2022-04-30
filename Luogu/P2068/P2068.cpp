#include <iostream>

using std::cin;
using std::cout;

char op;
long long n, m, x, y;
long long d[400005], laz[400005];

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
		laz[p << 1] += laz[p];
		laz[(p << 1) + 1] += laz[p];
		d[p << 1] += (k - s + 1) * laz[p];
		d[(p << 1) + 1] += (t - k) * laz[p];
		laz[p] = 0;
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

	if (laz[p])
	{
		laz[p << 1] += laz[p];
		laz[(p << 1) + 1] += laz[p];
		d[p << 1] += (k - s + 1) * laz[p];
		d[(p << 1) + 1] += (t - k) * laz[p];
		laz[p] = 0;
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

	d[p] = d[p << 1] + d[(p << 1) + 1];

	return sum;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;
	while (m--)
	{
		cin >> op >> x >> y;
		if (op == 'x')
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

