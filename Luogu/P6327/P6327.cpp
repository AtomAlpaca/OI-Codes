#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 2e5;

int u, v, w, op, n, m;
//
// sum(sin(a+b))=s
// st[x] = st[x] * cos(b) + 
//
//
//

long long laz[MAX << 2], a[MAX];
double sn[MAX << 2], cs[MAX << 2];

void pd(int x)
{
	if (!laz[x])
	{
		return ;
	}
	laz[x << 1] += laz[x];
	laz[x << 1 | 1] += laz[x];
	double cs1 = cs[x << 1], cs2 = cs[x << 1 | 1];
	double sn1 = sn[x << 1], sn2 = sn[x << 1 | 1];
	sn[x << 1] = sn1 * cos(laz[x]) + cs1 * sin(laz[x]);
	sn[x << 1 | 1] = sn2 * cos(laz[x]) + cs2 * sin(laz[x]);
	cs[x << 1] = cs1 * cos(laz[x]) - sn1 * sin(laz[x]); 
	cs[x << 1 | 1] = cs2 * cos(laz[x]) - sn2 * sin(laz[x]); 
	laz[x] = 0;
	return ;
}

void pu(int x)
{
	sn[x] = sn[x << 1] + sn[x << 1 | 1];
	cs[x] = cs[x << 1] + cs[x << 1 | 1];
	return ;
}

void build(int l, int r, int x)
{
	if (l == r)
	{
		sn[x] = sin((double)a[l]);
		cs[x] = cos((double)a[l]);
		return ;
	}
	int k = l + ((r - l) >> 1);
	build(l, k, x << 1);
	build(k + 1, r, x << 1 | 1);
	pu(x);
	return ;
}

void add(int l, int r, int c, int s, int t, int x)
{
	if (l >= s and r <= t)
	{
		laz[x] += c;
		double cs1 = cs[x], sn1 = sn[x];
		cs[x] = cs1 * cos(c) - sn1 * sin(c);
		sn[x] = sn1 * cos(c) + cs1 * sin(c);
		return ;
	}
	pd(x);
	int k = l + ((r - l) >> 1);
	if (s <= k)
	{
		add(l, k, c, s, t, x << 1);
	}
	if (t > k)
	{
		add(k + 1, r, c, s, t, x << 1 | 1);
	}
	pu(x);
	return ;
}

double get(int l, int r, int s, int t, int x)
{
	if (l >= s and r <= t)
	{
		return sn[x];
	}
	pd(x);
	int k = l + ((r - l) >> 1);
	double sum = 0;
	if (s <= k)
	{
		sum += get(l, k, s, t, x << 1);
	}
	if (t > k)
	{
		sum += get(k + 1, r, s, t, x << 1 | 1);
	}
	pu(x);
	return sum;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	build(1, n, 1);

	cin >> m;
	while (m--)
	{
		cin >> op;
		if (op == 1)
		{
			cin >> u >> v >> w;
			add(1, n, w, u, v, 1);
		}
		else
		{
			cin >> u >> v;
			cout << std::fixed << std::setprecision(1) <<  get(1, n, u, v, 1) << '\n';
		}
	}
}

