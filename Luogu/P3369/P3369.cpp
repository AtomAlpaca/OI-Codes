#include <iostream>
#include <utility>
#include <random>

using std::cin;
using std::cout;
using std::pair;

std::mt19937 rnd (0x17000001);

struct Treap
{
	int tot, rt;
	struct Node
	{
		int lch, rch, cnt, val, pri, siz;
	}t[100005];

	Treap()
	{
		tot = 0;
		rt  = 0;
		t[0] = {0, 0, 0, -(2 << 16), 0, 0};
	}
	inline void upd(int x)
	{
		t[x].siz = t[t[x].lch].siz + t[t[x].rch].siz + t[x].cnt;
	}

	pair <int, int> split(int x, int key)
	{
		if (!x)
		{
			return {0, 0};
		}
		if (t[x].val <= key)
		{
			pair <int, int> o = split(t[x].rch, key);
			t[x].rch = o.first;
			upd(x);
			return {x, o.second};
		}
		else
		{
			pair <int, int> o = split(t[x].lch, key);
			t[x].lch = o.second;
			upd(x);
			return {o.first, x};
		}
	}

	int merge(int x, int y)
	{
		if (!x)
		{
			return y;
		}
		if (!y)
		{
			return x;
		}
		
		if (t[x].pri > t[y].pri)
		{
			t[x].rch = merge(t[x].rch, y);
			upd(x);
			return x;
		}
		else
		{
			t[y].lch = merge(x, t[y].lch);
			upd(y);
			return y;
		}
	}

	int add(int val)
	{
		++tot;
		t[tot].val = val;
		t[tot].lch = 0;
		t[tot].rch = 0;
		t[tot].cnt = 1;
		t[tot].siz = 1;
		t[tot].pri = rnd();
		return tot;
	}

	void ins(int val)
	{
		pair <int, int> o = split(rt, val);
		pair <int, int> p = split(o.first, val - 1);
		if (!p.second)
		{
			p.second = add(val);
		}
		else
		{
			++t[p.second].siz;
			++t[p.second].cnt;
		}
		rt = merge(merge(p.first, p.second), o.second);
		return ;
	}

	void del(int val)
	{
		pair <int, int> o = split(rt, val);
		pair <int, int> p = split(o.first, val - 1);

		if (p.second)
		{
			--t[p.second].siz;
			--t[p.second].cnt;
		}

		rt = merge(merge(p.first, p.second), o.second);
		return ;
	}

	int rank(int val)
	{
		pair <int, int> o = split(rt, val - 1);
		int a = t[o.first].siz + 1;
		rt = merge(o.first, o.second);
		return a;
	}

	int kth(int x, int rk)
	{
		if (t[t[x].lch].siz >= rk)
		{
			return kth(t[x].lch, rk);
		}
		if (t[x].cnt + t[t[x].lch].siz >= rk)
		{
			return t[x].val;
		}
		return kth(t[x].rch, rk - t[x].cnt - t[t[x].lch].siz);
	}

	int last(int val)
	{
		pair <int, int> o = split(rt, val - 1);
		if (!o.first)
		{
			return 0;
		}
		int a = kth(o.first, t[o.first].siz);
		rt = merge(o.first, o.second);
		return a;
	}

	int next(int val)
	{
		pair <int, int> o = split(rt, val);
		int a = kth(o.second, 1);
		rt = merge(o.first, o.second);
		return a;
	}
} tre;

int n, op, m;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n;
	while (n--)
	{
		cin >> op >> m;
		if (op == 1)
		{
			tre.ins(m);
		}
		else if (op == 2)
		{
			tre.del(m);
		}
		else if (op == 3)
		{
			cout << tre.rank(m) << '\n';
		}
		else if (op == 4)
		{
			cout << tre.kth(tre.rt, m) << '\n';
		}
		else if (op == 5)
		{
			cout << tre.last(m) << '\n';
		}
		else
		{
			cout << tre.next(m) << '\n';
		}
	}

	return 0;
}
