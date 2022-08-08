#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;

std::mt19937 rnd(0x26214400);

int op, c, w;

struct Treap
{
	int tot, rt;
	struct Node
	{
		long long lch, rch, val, cos, siz, cnt, pri;
	} t[100005];

	Treap()
	{
		tot = rt = 0;
	}

	void upd(int x)
	{
		t[x].siz = t[t[x].lch].siz + t[t[x].rch].siz + t[x].cnt;
		return ;
	}

	int add(int val, int cos)
	{
		++tot;
		t[tot] = {0, 0, val, cos, 1, 1, int(rnd())};
		return tot;
	}

	pair <int, int> split(int x, int cos)
	{
		if (!x)
		{
			return {0, 0};
		}
		if (t[x].cos <= cos)
		{
			pair <int, int> o = split(t[x].rch, cos);
			t[x].rch = o.first;
			upd(x);
			return {x, o.second};
		}
		else
		{
			pair <int, int> o = split(t[x].lch, cos);
			t[x].lch = o.second;
			upd(x);
			return {o.first, x};
		}
	}

	pair <int, int> split2(int x, int siz)
	{
		if (!x)
		{
			return {0, 0};
		}
		if (t[t[x].lch].siz + t[x].cnt <= siz)
		{
			pair <int, int> o = split2(t[x].rch, siz - t[t[x].lch].siz - t[x].cnt);
			t[x].rch = o.first;
			upd(x);
			return {x, o.second};
		}
		else
		{
			pair <int, int> o = split2(t[x].lch, siz);
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

	void ins(int val, int cos)
	{
		pair <int, int> o = split(rt, cos);
		pair <int, int> p = split(o.first, cos - 1);
		
		if (!p.second)
		{
			p.second = add(val, cos);
		}

		rt = merge(merge(p.first, p.second), o.second);
		
		return ;
	}

	void delMax()
	{
		pair <int, int> o = split2(rt, t[rt].siz - 1);
		rt = o.first;
		return ;
	}

	void delMin()
	{
		pair <int, int> o = split2(rt, 1);
		rt = o.second;
		return ;
	}

	pair <int, int> dfs(int x)
	{
		if (!x)
		{
			return {0, 0};
		}
		pair <int, int> o = {t[x].val, t[x].cos};

		pair <int, int> a1 = dfs(t[x].lch);
		pair <int, int> a2 = dfs(t[x].rch);

		return {o.first  + a1.first  + a2.first,
				o.second + a1.second + a2.second};
	}
} tre;


int main()
{
	while (true)
	{
		cin >> op;
		if (op == -1)
		{
			pair <int, int> ans = tre.dfs(tre.rt);
			cout << ans.first << ' ' << ans.second;
			return 0;
		}
		else if (op == 1)
		{
			cin >> w >> c;
			tre.ins(w, c);
		}
		else if (op == 2)
		{
			if (tre.t[tre.rt].siz)
			{
				tre.delMax();
			}
		}
		else
		{
			if (tre.t[tre.rt].siz)
			{
				tre.delMin();
			}
		}
	}
}
