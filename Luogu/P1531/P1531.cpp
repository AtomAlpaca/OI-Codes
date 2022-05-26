#include <iostream>

using std::cin;
using std::cout;

char op;
int x, y, n, m;
int a[200005], d[1000005];

void pushup(int p)
{
	d[p] = std::max(d[p << 1], d[(p << 1) + 1]);
	return ;
}

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
	pushup(p);
	return ;
}

int ans(int l, int r, int s, int t, int p)
{
	if (l <= s and r >= t)
	{
		return d[p];
	}
	
	int k = s + ((t - s) >> 1);

	int top = -1e9;

	if (l <= k)
	{
		top = std::max(top, ans(l, r, s, k, p << 1));
	}
	if (r > k)
	{
		top = std::max(top, ans(l, r, k + 1, t, (p << 1) + 1));
	}

	pushup(p);
	return top;
}

void update(int l, int c, int s, int t, int p)
{
	if (s == t)
	{
		if (d[p] < c)
		{
			d[p] = c;
		}
		return ;
	}
	int k = s + ((t - s) >> 1);

	if (l <= k)
	{
		update(l, c, s, k, p << 1);	
	}
	else
	{
		update(l, c, k + 1, t, (p << 1) + 1);
	}

	pushup(p);
	return ;
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
		if (op == 'Q')
		{
			cout << ans(x, y, 1, n, 1) << '\n';
		}
		else
		{
			update(x, y, 1, n, 1);
		}
	}
	return 0;
}
