#include <iostream>
#include <random>
#include <utility>

using std::cin;
using std::cout;
using std::pair;

std::mt19937 rnd(0x21150687);

struct Treap
{
	int tot, rt;
	struct Nod
	{
		int lch, rch, val, pri, cnt, siz;
	} t[300005];

	Treap()
	{
		tot = 0;
		rt  = 0;
	}

	int add(int val)
	{
		++tot;
		t[tot] = {0, 0, val, int(rnd()), 1, 1};
		return tot;
	}

	void upd(int x)
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

	int lower(int min)
	{
		pair <int, int> o = split(rt, min - 1);
		rt = o.second;
		return t[o.first].siz;
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
			return kth(t[x].rch, rk - t[t[x].lch].siz - t[x].cnt);
		}
	}
} tre;

int T, min, k, del, ans;
char op;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T >> min;
	while (T--)
	{
		cin >> op >> k;
		if (op == 'I')
		{
			if (k >= min)
			{
				k -= del;
				tre.ins(k);
			}
		}
		else if (op == 'A')
		{
			del += k;
		}
		else if (op == 'S')
		{
			del -= k;
			ans += tre.lower(min - del);
		}
		else
		{
			if (k > tre.t[tre.rt].siz)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << tre.kth(tre.rt, tre.t[tre.rt].siz - k + 1) + del << '\n';
			}
		}
	}

	cout << ans;

	return 0;
}
