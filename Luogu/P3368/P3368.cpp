#include <iostream>

using std::cin;
using std::cout;

int n, m, op, x, y, z;
long long a[500005], d[2000005], laz[2000005];

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
		laz[p] += c;
		return ;
	}

	int k = s + ((t - s) >> 1);

	if (s != t and laz[p])
	{
		d[p << 1] += laz[p] * (k - s + 1);
		d[(p << 1) + 1] += laz[p] * (t - k);
		laz[p << 1] += laz[p];
		laz[(p << 1) + 1] += laz[p];
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

int getsum(int l, int r, int s, int t, int p)
{
	if (l <= s and r >= t)
	{
		return d[p];
	}

	int k = s + ((t - s) >> 1);

	if (laz[p])
	{
		d[p << 1] += laz[p] * (k - s + 1);
		d[(p << 1) + 1] += laz[p] * (t - k);
		laz[p << 1] += laz[p];
		laz[(p << 1) + 1] += laz[p];
		laz[p] = 0;
	}

	int sum = 0;

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
		cin >> op >> x;
		if (op == 1)
		{
			cin >> y >> z;
			update(x, y, z, 1, n, 1);
		}
		else
		{
			cout << getsum(x, x, 1, n, 1) << '\n';
		}
	}
	return 0;
}

