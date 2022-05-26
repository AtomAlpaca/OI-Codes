#include <iostream>

using std::cin;
using std::cout;

int m, n, x, y;
int a[180005], d[800005], e[800005];

void pushup(int p)
{
	d[p] = std::max(d[p << 1], d[(p << 1) + 1]);
	e[p] = std::min(e[p << 1], e[(p << 1) + 1]);
	return ;
}

void build(int l, int r, int p)
{
	if (l == r)
	{
		d[p] = a[l];
		e[p] = a[l];
		return ;
	}

	int k = l + ((r - l) >> 1);

	build(l, k, p << 1);
	build(k + 1, r, (p << 1) + 1);

	pushup(p);

	return ;
}

int findb(int l, int r, int s, int t, int p)
{
	if (l <= s and r >= t)
	{
		return d[p];
	}

	int k = s + ((t - s) >> 1);

	int ans = -1e9;

	if (l <= k)
	{
		ans = std::max(ans, findb(l, r, s, k, p << 1));
	}
	if (r > k)
	{
		ans = std::max(ans, findb(l, r, k + 1, t, (p << 1) + 1));
	}

	pushup(p);

	return ans;
}

int finds(int l, int r, int s, int t, int p)
{
	if (l <= s and r >= t)
	{
		return e[p];
	}

	int k = s + ((t - s) >> 1);

	int ans = 1e9;

	if (l <= k)
	{
		ans = std::min(ans, finds(l, r, s, k, p << 1));
	}
	if (r > k)
	{
		ans = std::min(ans, finds(l, r, k + 1, t, (p << 1) + 1));
	}

	pushup(p);

	return ans;
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
		cin >> x >> y;
		cout << findb(x, y, 1, n, 1) - finds(x, y, 1, n, 1) << '\n';
	}

	return 0;
}
