#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 2e5 + 5;

struct Node
{
	int lch, rch, val;
} a[MAX << 5];

std::vector <int> vec;

int tot, n, m, u, v, w;
int nums[MAX], rt[MAX];

int build(int l, int r)
{
	++tot;
	int p = tot;

	if (l == r)
	{
		return p;
	}

	int k = l + ((r - l) >> 1);

	a[p].lch = build(l, k);
	a[p].rch = build(k + 1, r);
	return p;
}

int ins(int o, int l, int r, int x)
{
	++tot;
	int p = tot;

	a[p] = a[o];

	if (l == r)
	{
		++a[p].val;
		return p;
	}

	int k = l + ((r - l) >> 1);

	if (x <= k)
	{
		a[p].lch = ins(a[o].lch, l, k, x);
	}
	else
	{
		a[p].rch = ins(a[o].rch, k + 1, r, x);
	}

	a[p].val = a[a[p].lch].val + a[a[p].rch].val;

	return p;
}

int get(int s, int t, int l, int r, int x)
{
	if (l == r)
	{
		return l;
	}

	int val = a[a[t].lch].val - a[a[s].lch].val;
	int k = l + ((r - l) >> 1);

	if (x <= val)
	{
		return get(a[s].lch, a[t].lch, l, k, x);
	}
	else
	{
		return get(a[s].rch, a[t].rch, k + 1, r, x - val);
	}
}

int find(int x)
{
	return std::lower_bound(vec.begin(), vec.end(), x) - vec.begin();
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		cin >> nums[i];
		vec.push_back(nums[i]);
	}

	std::sort(vec.begin(), vec.end());
	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

	rt[0] = build(0, vec.size() - 1);

	for (int i = 1; i <= n; ++i)
	{
		rt[i] = ins(rt[i - 1], 0, vec.size() - 1, find(nums[i]));
	}

	while (m--)
	{
		cin >> u >> v >> w;
		cout << vec.at(get(rt[u - 1], rt[v], 0, vec.size() - 1, w)) << '\n';
	}

	return 0;
}
