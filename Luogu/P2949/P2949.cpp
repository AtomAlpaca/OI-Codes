#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;

long long n, p, ans, tim;
const int MAX = 1e7 + 5;

struct Work
{
	int t, p;
} w[MAX];

bool cmp(Work w1, Work w2)
{
	if (w1.t == w2.t)
	{
		return w1.p > w2.p;
	}
	return w1.t < w2.t;
}

struct Heap
{
	int tot;
	int wei[MAX];
	
	void pushup(int x)
	{
		while (wei[x >> 1] > wei[x] and x > 1)
		{
			std::swap(wei[x], wei[x >> 1]);
			x >>= 1;
		}
	}

	void pushdown(int x)
	{
		while (true)
		{
			int k = x;
			if (wei[x << 1] < wei[k] and (x << 1) <= tot)
			{
				k = x << 1;
			}
			if (wei[x << 1 | 1] < wei[k] and (x << 1 | 1) <= tot)
			{
				k = x << 1 | 1;
			}
			if (k == x)
			{
				break;
			}
			std::swap(wei[x], wei[k]);
			x = k;
		}
	}

	void add(int x)
	{
		++tot;
		wei[tot] = x;
		pushup(tot);
		return ;
	}

	void pop()
	{
		std::swap(wei[1], wei[tot]);
		--tot;
		pushdown(1);
	}

	int top()
	{
		return wei[1];
	}

	int size()
	{
		return tot;
	}
} h;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> w[i].t >> w[i].p;
	}

	std::sort(w + 1, w + n + 1, cmp);

	for (int i = 1; i <= n; ++i)
	{
		tim = w[i].t;
		if (tim - h.size() == 0)
		{
			if (h.top() >= w[i].p)
			{
				continue;
			}
			ans = ans - h.top() + w[i].p;
			h.pop();
			h.add(w[i].p);
		}
		else
		{
			ans += w[i].p;
			h.add(w[i].p);
		}
	}

	cout << ans;
	return 0;
}

