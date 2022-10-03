#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;

int n, a;
const int MAX = 100005;

std::mt19937 rnd(0x170001);

struct Treap
{
	int rt, tot;
	struct Node
	{
		int lch, rch, siz, cnt, val, rnd;
	}a[MAX];

	Treap()
	{
		rt = tot = 0;
	}

	int add(int x)
	{
		++tot;
		a[tot] = {0, 0, 1, 1, x, (int)rnd()};
		return tot;
	}

	void upd(int x)
	{
		a[x].siz = a[a[x].lch].siz + a[a[x].rch].siz + a[x].cnt;
		return ;
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
		if (a[x].rnd > a[y].rnd)
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
			++a[p.second].cnt;
			++a[p.second].siz;
		}

		rt = merge(merge(p.first, p.second), o.second);
		return ;
	}

	int kth(int x, int k)
	{
		if (a[a[x].lch].siz >= k)
		{
			return kth(a[x].lch, k);
		}
		else if (a[a[x].lch].siz + a[x].cnt >= k)
		{
			return a[x].val;
		}
		else
		{
			return kth(a[x].rch, k - a[a[x].lch].siz - a[x].cnt);
		}
	}
} tre;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> a;
		tre.ins(a);
		if (i & 1)
		{
			cout << tre.kth(tre.rt, i / 2 + 1) << '\n';
		}
	}
	return 0;
}
