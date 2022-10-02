#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;

//std::mt19937 rnd(0x170001);
int m, q, op, x, v, n;

struct Treap
{
	int rt, tot;
	struct Node
	{
		int lch, rch, val, rnd, cnt, siz;
	} a[200055];
	
	Treap()
	{
		tot = rt = 0;
		a[0] = {0, 0, 0, -(2 << 16), 0, 0};
		srand(int(time(0)));
	}
	
	int add(int x)
	{
		++tot;
		a[tot].lch = a[tot].rch = 0;
		a[tot].val = x;
		a[tot].rnd = rand();
		a[tot].cnt = a[tot].siz = 1;
		return tot;
	}
	
	void upd(int x)
	{
		a[x].siz = a[x].cnt + a[a[x].lch].siz + a[a[x].rch].siz;
		return ;
	}
	
	pair <int, int> sqlit(int x, int key)
	{
		if (!x)
		{
			return std::make_pair(0, 0);
		}
		if (a[x].val <= key)
		{
			pair <int, int> o = sqlit(a[x].rch, key);
			a[x].rch = o.first;
			upd(x);
			return std::make_pair(x, o.second);
		}
		else
		{
			pair <int, int> o = sqlit(a[x].lch, key);
			a[x].lch = o.second;
			upd(x);
			return std::make_pair(o.first, x);
		}
	}
	
	int merge(int x, int y)
	{
		if (!x or !y)
		{
			return x + y;
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
		pair <int, int> o = sqlit(rt, x);
		pair <int, int> p = sqlit(o.first, x - 1);
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
	}
	
	int rank(int x, int key)
	{
		if (a[a[x].lch].siz >= key)
		{
			return rank(a[x].lch, key);
		}
		else if (a[a[x].lch].siz + a[x].cnt >= key)
		{
			return a[x].val;
		}
		else
		{
			return rank(a[x].rch, key - a[x].cnt - a[a[x].lch].siz);
		}
	}
} tre;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	cin >> m >> q;
	for (int i = 1; i <= m; ++i)
	{
		cin >> v;
		tre.ins(v);
	}

	for (int i = 1; i <= q; ++i)
	{
		cin >> op >> n;
		if (op == 1)
		{
			cout << tre.rank(tre.rt, tre.a[tre.rt].siz - n + 1) << '\n';
		}
		else
		{
			tre.ins(n);
		}
	}	
	return 0;
}
