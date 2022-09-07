#include <iostream>
#include <utility>
#include <random>

using std::cin;
using std::cout;
using std::pair;

std::mt19937 rnd(0x17000001);

int a, ans, n;

struct Treap
{
	int tot, rt;
	
	struct Node
	{
		int lch, rch, val, cnt, siz, pri;
	} t[33005];

	Treap()
	{
		tot = rt = 0;
		t[0] = {0, 0, -1, 0, 0, 0};
	}

	void upd(int x)
	{
		t[x].siz = t[t[x].lch].siz + t[t[x].rch].siz + t[x].cnt;
		return ;
	}

	int add(int val)
	{
		++tot;
		t[tot] = {0, 0, val, 1, 1, int(rnd())};
		return tot;
	}

	pair <int, int> split(int x, int k)
	{
		if (!x)
		{
			return {0, 0};
		}
		if (t[x].val <= k)
		{
			pair <int, int> o = split(t[x].rch, k);
			t[x].rch = o.first;
			upd(x);
			return {x, o.second};
		}
		else
		{
			pair <int, int> o = split(t[x].lch, k);
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

	int kth(int x, int rk)
	{
		if (t[t[x].lch].siz >= rk)
		{
			return kth(t[x].lch, rk);
		}
		else if (t[t[x].lch].siz + t[x].cnt >= rk)
		{
			return t[x].val;
		}
		else
		{
			return kth(t[x].rch, rk - t[x].cnt - t[t[x].lch].siz);
		}
	}

	int ans(int val)
	{
		pair <int, int> o = split(rt, val);
		pair <int, int> p = split(o.first, val - 1);
		int m = (2 << 20);
		if (p.second)
		{
			m = 0;
		}
		else
		{
			if (p.first)
			{
				m = std::min(m, std::abs(val - kth(p.first, t[p.first].siz)));
			}
			if (o.second)
			{
				m = std::min(m, std::abs(val - kth(o.second, 1)));
			}
		}
		rt = merge(merge(p.first, p.second), o.second);
		return m;
	}

} tre;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> a;
	ans += a;
	tre.ins(a);
	for (int i = 2; i <= n; ++i)
	{
		cin >> a;
		ans += tre.ans(a);
		tre.ins(a);
	}

	cout << ans;
	return 0;
}
