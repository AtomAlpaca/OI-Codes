#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;

const long long INF = 0x3f3f3f3f;

long long n, m, ans, ak;

struct Heap
{
	long long tot;
	long long a[200005];

	Heap()
	{
		for (int i = 1; i <= 200005; ++i)
		{
			a[i] = -INF;
		}
		tot = 0;
	}

	void pushup(int x)
	{
		while (a[x >> 1] < a[x] and x > 1)
		{
			std::swap(a[x >> 1], a[x]);
			x >>= 1;
		}
	}

	void pushdown(long long x)
	{
		while (true)
		{
			int k = x;
			if (a[x] < a[x << 1] and a[x << 1] != -INF)
			{
				k = x << 1;
			}
			if (a[k] < a[(x << 1) + 1] 
			and a[(x << 1) + 1] != -INF 
			and a[(x << 1) + 1] > a[x << 1])
			{
				k = (x << 1) + 1;
			}
			if (x == k)
			{
				return ;
			}

			std::swap(a[x], a[k]);
			x = k;
		}
	}

	void push(long long x)
	{
		++tot;
		a[tot] = x;
		pushup(tot);
		return ;
	}

	void pop()
	{
		std::swap(a[1], a[tot]);
		a[tot] = -INF;
		pushdown(1);
		--tot;
		return ;
	}

	int top()
	{
		return a[1];
	}
} h;

struct Node
{
	long long pos, tim;
} t[200005];

bool cmp(Node n1, Node n2)
{
	return n1.pos < n2.pos;
}

int main()
{
	
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		cin >> t[i].pos >> t[i].tim;
	}

	std::sort(t + 1, t + n + 1, cmp);

	long long k = 0;

	for (int i = 1; i <= n; ++i)
	{
		k += t[i].pos - t[i - 1].pos + t[i].tim;
		h.push(t[i].tim);
		++ans;

		while (k > m and h.tot != 0)
		{
			k -= h.top();
			h.pop();
			--ans;
		}

		if (k > m)
		{
			break ;
		}

		ak = std::max(ak, ans);
	}

	cout << ak;
	return 0;
}
