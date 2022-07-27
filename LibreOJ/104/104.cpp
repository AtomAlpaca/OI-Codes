#include <iostream>
#include <utility>
#include <random>

using std::cin;
using std::cout;
using std::pair;

std::mt19937 rnd (0x14285714);

struct Treap
{
	int rt, tot;
	struct Node
	{
		int lch, rch, val, pri, cnt, siz;
	} t[100005];

	Treap()
	{
		rt  = 0;
		tot = 0;
		t[0] = {0, 0, 0, -(2 << 16), 0, 0};
	}

	inline void upd(int x)
	{
		t[x].siz = t[t[x].lch].siz + t[t[x].rch].siz + t[x].cnt;
		return ;
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

		if (t[x].pri >= t[y].pri)
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
		t[tot].lch = t[tot].rch = 0;
		t[tot].siz = t[tot].cnt = 1;
		t[tot].val = val;
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
			++t[p.second].cnt;
			++t[p.second].siz;
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
			--t[p.second].cnt;
			--t[p.second].siz;
		}
		rt = merge(merge(p.first, p.second), o.second);
		return ;
	}

	int rank(int val)
	{
		pair <int, int> o = split(rt, val - 1);
		int res = t[o.first].siz + 1;
		rt = merge(o.first, o.second);
		return res;
	}

	int find(int x, int rank)
	{
		if (rank <= t[t[x].lch].siz)
		{
			return find(t[x].lch, rank);
		}
		else if (rank <= t[t[x].lch].siz + t[x].cnt)
		{
			return t[x].val;
		}
		else
		{
			return find(t[x].rch, rank - t[t[x].lch].siz - t[x].cnt);
		}
	}

	int last(int val)
	{
		pair <int, int> o = split(rt, val - 1);
		int res = find(o.first, t[o.first].siz);
		rt = merge(o.first, o.second);
		return res;
	}

	int next(int val)
	{
		pair <int, int> o = split(rt, val);
		int res = find(o.second, 1);
		rt = merge(o.first, o.second);
		return res;
	}

} tre;

int op, n, m;

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
			cout << tre.find(tre.rt, m) << '\n';
		}
		else if (op == 5)
		{
			cout << tre.last(m) << '\n';
		}
		else if (op == 6)
		{
			cout << tre.next(m) << '\n';
		}
	}
	return 0;
}
