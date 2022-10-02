#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;

std::mt19937 rnd(0x170001);

int m, n;
int c[200005], u[200005];

struct Treap
{
	int tot, rt;
	struct Node
	{
		int lch, rch, val, siz, cnt, rnd;
	} a[200005];

	Treap()
	{
		tot = rt = 0;
	}

	int add(int x)
	{
		++tot;
		a[tot] = {0, 0, x, 1, 1, (int)rnd()};
		return tot;
	}

	void upd(int x)
	{
		a[x].siz = a[a[x].lch].siz + a[a[x].rch].siz + a[x].cnt;
	}

	pair <int, int> split(int x, int key)
	{
		if (!x)
		{
			return {0, 0};
		}
		if (a[x].val <= key)
		{
			pair <int, int> o = split(a[x].rch, key);
			a[x].rch = o.first;
			upd(x);
			return {x, o.second};
		}
		else
		{
			pair <int, int> o = split(a[x].lch, key);
			a[x].lch = o.second;
			upd(x);
			return {o.first, x};
		}
	}

	int merge(int x, int y)
	{
		if (!x or !y)
		{
			return x | y;
		}
		if (a[x].rnd >= a[y].rnd)
		{
			a[x].rch = merge(a[x].rch, y);
			upd(x);
			return x;
		}
		else
		{
			a[y].lch = merge(x, a[y].lch);
			upd(y);
			return y;
		}
	}

	void ins(int x)
	{
		pair <int, int> o = split(rt, x);
		pair <int, int> p = split(o.first, x - 1);

		if (!p.second)
		{
			p.second = add(x);
		}
		else
		{
			++a[p.second].siz;
			++a[p.second].cnt;
		}

		rt = merge(merge(p.first, p.second), o.second);
		return ;
	}

	int kth(int o, int x)
	{
		if (a[a[o].lch].siz >= x)
		{
			return kth(a[o].lch, x);
		}
		else if (a[a[o].lch].siz + a[o].cnt >= x)
		{
			return a[o].val;
		}
		else
		{
			return kth(a[o].rch, x - a[o].cnt - a[a[o].lch].siz);
		}
	}
} tre;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> m >> n;

	for (int i = 1; i <= m; ++i)
	{
		cin >> c[i];
	}

	for (int i = 1; i <= n; ++i)
	{
		cin >> u[i];
	}

	int top = 1;

	for (int i = 1; i <= m; ++i)
	{
		tre.ins(c[i]);
		while (i == u[top])
		{
			cout << tre.kth(tre.rt, top) << '\n';
			++top;
		}
	}

	
	return 0;
}
