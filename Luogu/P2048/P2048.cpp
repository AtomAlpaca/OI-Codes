#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int MAX = 5e5 + 5;

int flag[MAX];

struct Heap
{
	long long tot;
	long long h[MAX << 1], p[MAX << 1];

	long long th()
	{
		return h[1];
	}

	long long tp()
	{
		return p[1];
	}
	
	void pu(int x)
	{
		while (x > 1 and h[x >> 1] < h[x])
		{
			std::swap(h[x], h[x >> 1]);
			std::swap(p[x], p[x >> 1]);
			x >>= 1;
		}
	}

	void pd(int x)
	{
		while (true)
		{
			int k = x;
			if ((x << 1) <= tot and h[x << 1] > h[k])
			{
				k = x << 1;
			}
			if ((x << 1 | 1) <= tot and h[x << 1 | 1] > h[k])
			{
				k = x << 1 | 1;
			}
			if (k == x)
			{
				break;
			}
			std::swap(h[x], h[k]);
			std::swap(p[x], p[k]);
			x = k;
		}
	}

	void ins(int x, int y)
	{
		++tot;
		h[tot] = x, p[tot] = y;
		pu(tot);
	}

	void pop()
	{
		std::swap(h[1], h[tot]);
		std::swap(p[1], p[tot]);
		--tot;
		pd(1);
	}
} heap;

struct st
{
	long long tot;
	long long a[MAX * 30], rt[MAX * 30], lch[MAX * 30], rch[MAX * 30];

	long long build(long long l, long long r)
	{
		++tot;
		int p = tot;
		if (l == r)
		{
			return p;
		}

		int k = l + ((r - l) >> 1);

		lch[p] = build(l, k), rch[p] = build(k + 1, r);
		return p;
	}

	int ins(int o, int l, int r, int x)
	{
		++tot;
		int p = tot;
		a[p] = a[o], lch[p] = lch[o], rch[p] = rch[o];
		if (l == r)
		{
			++a[p];
			return p;
		}

		long long k = l + ((r - l) >> 1);
		if (x <= k)
		{
			lch[p] = ins(lch[o], l, k, x);
		}
		else
		{
			rch[p] = ins(rch[o], k + 1, r, x);
		}
		a[p] = a[lch[p]] + a[rch[p]];
		return p;
	}

	long long get(int l, int r, int x, int y, int o)
	{
		if (l == r)
		{
			return l;
		}

		int k = l + ((r - l) >> 1);

		if (a[lch[y]] - a[lch[x]] >= o)
		{
			return get(l, k, lch[x], lch[y], o);
		}
		else
		{
			return get(k + 1, r, rch[x], rch[y], o - (a[lch[y]] - a[lch[x]]));
		}
	}
} st;


using std::vector;

long long n, k, b, c, ans;
long long v[MAX], sum[MAX];
vector <long long> s;

long long find(long long x)
{
	return std::lower_bound(s.begin(), s.end(), x) - s.begin();
}

int main()
{
	cin >> n >> k >> b >> c;
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		sum[i] = sum[i - 1] + v[i];
	}

	for (int i = 1; i <= n; ++i)
	{
		s.push_back(sum[i]);
	}

	std::sort(s.begin(), s.end());
	s.erase(std::unique(s.begin(), s.end()), s.end());

	st.rt[0] = st.build(0, s.size() - 1);

	int len = c - b + 1;
	for (int i = 1; i <= n; ++i)
	{
		st.rt[i] = st.ins(st.rt[i - 1], 0, s.size() - 1, find(sum[i]));
		flag[i] = 1;
	}


	for (int i = 1; i + b - 1 <= n; ++i)
	{
		const int L = std::min(n, i + c - 1) - (i + b - 1) + 1;
		long long q = s.at(st.get(0, s.size() - 1, st.rt[i + b - 2], st.rt[std::min(i + c - 1, n)], L - flag[i] + 1));
		heap.ins(q - sum[i - 1], i);
	}

	while (k--)
	{
		int to = heap.tp();
		++flag[to];
		ans += heap.th();
		heap.pop();
		const int L = std::min(n, to + c - 1) - (to + b - 1) + 1;
		if (L - flag[to] + 1 > 0)
		{
			long long q = s.at(st.get(0, s.size() - 1, st.rt[to + b - 2], st.rt[std::min(to + c - 1, n)], L - flag[to] + 1)) - sum[to - 1];
			heap.ins(q, to);
		}
	}

	cout << ans;
	return 0;
}
