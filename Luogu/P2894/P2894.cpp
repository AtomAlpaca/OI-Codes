#include <iostream>

using std::cin;
using std::cout;

int op, x, y, n, m;

struct Room
{
	int l, r, a;
	int laz;
} f[500000 << 2];

void lazy(int l, int r, int x)
{
	if (!f[x].laz)
	{
		return ;
	}

	int k = l + ((r - l) >> 1);

	if (f[x].laz == 1)
	{
		f[x << 1].l = f[x << 1].r = f[x << 1].a = 
		f[x << 1 | 1].l = f[x << 1 | 1].r = f[x << 1 | 1].a = 0;
		f[x << 1].laz = f[x << 1 | 1].laz = 1;
	}
	else
	{
		f[x << 1].l = f[x << 1].r = f[x << 1].a =  k - l + 1;
		f[x << 1 | 1].l = f[x << 1 | 1].r = f[x << 1 | 1].a = r - k;
		f[x << 1].laz = f[x << 1 | 1].laz = 2;
	}

	f[x].laz = 0;
	
	return ;
}

void upd(int l, int r, int x)
{
	int k = l + ((r - l) >> 1);
	f[x].l = f[x << 1].l;
	f[x].r = f[x << 1 | 1].r;

	if (f[x << 1].l == k - l + 1)
	{
		f[x].l = k - l + 1 + f[x << 1 | 1].l;
	}
	if (f[x << 1 | 1].r == r - k)
	{
		f[x].r = r - k + f[x << 1].r;
	}
	
	f[x].a = std::max(std::max(f[x << 1].a, f[x << 1 | 1].a), f[x << 1].r + f[x << 1 | 1].l);
	return ;
}

void init(int l, int r, int x)
{
	f[x].l = f[x].r = f[x].a = r - l + 1;
	f[x].laz = 0;

	if (l == r)
	{
		return ;
	}

	int k = l + ((r - l) >> 1);

	init(l, k, x << 1);
	init(k + 1, r, x << 1 | 1);

	return ;
}

void change(int l, int r, bool c, int s, int t, int x)
{
	if (l >= s and r <= t)
	{
		if (!c)
		{
			f[x].l = f[x].r = f[x].a = 0;
			f[x].laz = 1;
		}
		else
		{
			f[x].l = f[x].r = f[x].a = r - l + 1;
			f[x].laz = 2;
		}
		return ;
	}

	int k = l + ((r - l) >> 1);
	lazy(l, r, x);
	
	if (s <= k)
	{
		change(l, k, c, s, t, x << 1);
	}
	
	if (t > k)
	{
		change(k + 1, r, c, s, t, x << 1 | 1);
	}
	upd(l, r, x);
	return ;
}

int find(int l, int r, int o, int x)
{
	if (l == r)
	{
		return l;
	}

	int k = l + ((r - l) >> 1);
	lazy(l, r, x);

	if (f[x << 1].a >= o)
	{
		return find(l, k, o, x << 1);
	}
	else if (f[x << 1].r + f[x << 1 | 1].l >= o)
	{
		return k - f[x << 1].r + 1;
	}
	else
	{
		return find(k + 1, r, o, x << 1 | 1);
	}
}

int main()
{
	cin >> n >> m;
	init(1, n, 1);
	
	while (m--)
	{
		cin >> op >> x;
		if (op == 1)
		{
			if (f[1].a < x)
			{
				cout << 0 << '\n';
				continue;
			}
			int ans = find(1, n, x, 1);
			change(1, n, false, ans, ans + x - 1, 1);
			cout << ans << '\n';
		}
		else
		{
			cin >> y;
			change(1, n, true, x, x + y - 1, 1);
		}
	}
	return 0;
}
