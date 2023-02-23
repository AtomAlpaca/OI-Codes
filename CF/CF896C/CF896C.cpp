#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::set;
using std::vector;
using std::pair;

const int MAX = 1e5 + 5;

struct Node
{
	long long l, r;
	mutable long long v;
	bool operator< (const Node &n) const
	{
		return l < n.l;
	}
};

set <Node> odt;
long long m, n, seed, vmax, u, v, l, r, op;
long long a[MAX];
typedef set<Node>::iterator iter;

iter split(long long x)
{
	iter it = odt.lower_bound(Node{x, 0, 0});
	if (it -> l == x and it != odt.end())
	{
		return it;
	}
	--it;
	
	long long L = it -> l, R = it -> r, V = it -> v;
	odt.erase(it);
	odt.insert(Node{L, x - 1, V});
	return odt.insert(Node{x, R, V}).first;
}

void assign(long long l, long long r, long long x)
{
	iter itr = split(r + 1);
	iter itl = split(l);
	odt.erase(itl, itr);
	odt.insert(Node{l, r, x});
	return ;
}

void add(long long l, long long r, long long x)
{
	iter itr = split(r + 1);
	iter itl = split(l);
	while (itl != itr)
	{
		itl -> v += x;
		++itl;
	}
	return ;
}

long long kth(long long l, long long r, long long k)
{
	vector <pair <long long, long long> > e;
	iter itr = split(r + 1);
	iter itl = split(l);
	while (itl != itr)
	{
		e.push_back(std::make_pair(itl -> v, (itl -> r) - (itl -> l) + 1));
		++itl;
	}

	std::sort(e.begin(), e.end());
	const int len = e.size();
	for (int i = 0; i < len; ++i)
	{
		k -= e.at(i).second;
		if (k <= 0)
		{
			return e.at(i).first;
		}
	}
	return -1;
}

long long qpow(long long x, long long y, long long z)
{
	x %= z;
	long long t = x % z;
	--y;
	while (y)
	{
		if (y & 1)
		{
			t = x * t % z;
		}
		x = x * x % z;
		y >>= 1;
	}
	return t % z;
}

long long sum(long long l, long long r, long long x, long long y)
{
	long long ans = 0;
	iter itr = split(r + 1);
	iter itl = split(l);
	while (itl != itr)
	{
		ans = ans + (qpow(itl -> v, x, y) * ((itl -> r) - (itl -> l) + 1) % y) % y;
		++itl;
	}
	return ans % y;
}

long long rnd()
{
	long long ret = seed;
	seed = (seed * 7 + 13) % 1000000007;
	return ret;
}

void init()
{
	for (int i = 1; i <= n; ++i)
	{
		a[i] = (rnd() % vmax) + 1;
		odt.insert(Node{i, i, a[i]});
	}

	for (int i = 1; i <= m; ++i)
	{
		op = (rnd() % 4) + 1;
		l  = (rnd() % n) + 1;
		r  = (rnd() % n) + 1;
		if (l > r)
		{
			std::swap(l, r);
		}
		if (op == 3)
		{
			u = (rnd() % (r - l + 1)) + 1;
		}
		else
		{
			u = (rnd() % vmax) + 1;
		}
		if (op == 4)
		{
			v = (rnd() % vmax) + 1;
		}

		if (op == 1)
		{
			add(l, r, u);
		}
		else if (op == 2)
		{
			assign(l, r, u);
		}
		else if (op == 3)
		{
			cout << kth(l, r, u) << '\n';
		}
		else
		{
			cout << sum(l, r, u, v) << '\n';
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n >> m >> seed >> vmax;
	init();
}

